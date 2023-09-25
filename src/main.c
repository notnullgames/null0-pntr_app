unsigned char* null0_load_file(const char* path, unsigned int* bytesRead);

#include <dirent.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <unistd.h>

#define PNTR_LOAD_FILE null0_load_file
#define PNTR_APP_IMPLEMENTATION
#define PNTR_ENABLE_DEFAULT_FONT
#define PNTR_DISABLE_MATH
#include "pntr_app.h"

#define ASSETSYS_IMPLEMENTATION
#define STRPOOL_IMPLEMENTATION
#include "assetsys.h"

// web49
#include "web49/api/api.h"
#include "web49/ast.h"
#include "web49/interp/interp.h"
#include "web49/opt/tee.h"
#include "web49/opt/tree.h"
#include "web49/read_bin.h"

#define CVECTOR_LOGARITHMIC_GROWTH
#include "cvector.h"

typedef struct AppData {
  pntr_font* font;
  pntr_image* screen;
  pntr_app* app;
  cvector_vector_type(pntr_font*) fonts;
  cvector_vector_type(pntr_image*) images;
  cvector_vector_type(pntr_sound*) sounds;
  assetsys_t* fs;
  uint32_t cart_load;
  uint32_t cart_update;
} AppData;

// struct of all your game state
AppData* null0;

// the filename of your cart
char* cartName = NULL;

unsigned char* null0_load_file(const char* path, unsigned int* bytesRead) {
  if (null0 == NULL || null0->fs == NULL || path == NULL) {
    pntr_app_log(PNTR_APP_LOG_ERROR, "Stuff not set.");
    return NULL;
  }

  // Load the file information from assetsys.
  assetsys_file_t file;
  if (assetsys_file(null0->fs, path, &file) != 0) {
    pntr_app_log(PNTR_APP_LOG_ERROR, "Could not get info.");
    return NULL;
  }

  // Find out the size of the file.
  int size = assetsys_file_size(null0->fs, file);
  if (size <= 0) {
    pntr_app_log(PNTR_APP_LOG_ERROR, "Could not get size.");
    return NULL;
  }

  // Create the memory buffer.
  unsigned char* out = PNTR_MALLOC(size);
  if (out == NULL) {
    pntr_app_log(PNTR_APP_LOG_ERROR, "Could not malloc");
    return NULL;
  }

  // Load the file into the buffer.
  int outSize = 0;
  if (assetsys_file_load(null0->fs, file, &outSize, (void*)out, size) != 0) {
    PNTR_FREE(out);
    pntr_app_log(PNTR_APP_LOG_ERROR, "Could not load into buffer");
    return NULL;
  }

  // Save how many bytes were read.
  if (bytesRead != NULL) {
    *bytesRead = outSize;
  }

  printf("load file: %s - %d\n%s\n", path, outSize, out);

  return out;
}

char* getDirectoryPath(const char* filePath) {
  // Find the last occurrence of the directory separator character ('/' or '\') in the file path
  const char* lastSeparator = strrchr(filePath, '/');
  if (lastSeparator == NULL) {
    lastSeparator = strrchr(filePath, '\\');  // Check for Windows-style path separator
  }

  if (lastSeparator != NULL) {
    // Calculate the length of the directory path
    size_t pathLength = lastSeparator - filePath + 1;

    // Allocate memory for the directory path
    char* directoryPath = (char*)malloc(pathLength + 1);

    // Copy the directory path into the allocated memory
    strncpy(directoryPath, filePath, pathLength);
    directoryPath[pathLength] = '\0';  // Null-terminate the string

    return directoryPath;
  } else {
    // No directory separator found, return NULL or handle the error accordingly
    return NULL;
  }
}

bool Init(pntr_app* app) {
  if (cartName == NULL) {
    pntr_app_log(PNTR_APP_LOG_ERROR, "Usage: null0 <ZIP_OR_WASM_OR_DIR>");
    return false;
  }

  bool isZip = false;
  bool isWasm = false;
  bool isDir = false;

  DIR* dirptr;
  if (access(cartName, F_OK) != -1) {
    if ((dirptr = opendir(cartName)) != NULL) {
      isDir = true;
    } else {
      FILE* fptr1 = fopen(cartName, "r");
      char str[4];
      if (fptr1 == NULL) {
        pntr_app_log(PNTR_APP_LOG_ERROR, "Could not open file.");
        return false;
      }
      fread(str, 4, 1, fptr1);
      fclose(fptr1);
      isZip = memcmp(str, "PK\3\4", 4) == 0;
      isWasm = memcmp(str, "\0asm", 4) == 0;
    }
  } else {
    pntr_app_log(PNTR_APP_LOG_ERROR, "Could not open file.");
    return false;
  }

  if (!isDir && !isZip && !isWasm) {
    pntr_app_log(PNTR_APP_LOG_ERROR, "Unknown filetype.");
    return false;
  }

  null0 = pntr_load_memory(sizeof(AppData));
  null0->fs = assetsys_create(0);

  if (isWasm) {
    assetsys_mount(null0->fs, getDirectoryPath(cartName), "/cart");
  } else {
    assetsys_mount(null0->fs, cartName, "/cart");
  }

  unsigned int bytesRead = 0;
  unsigned char* wasmBytes = null0_load_file("/cart/main.wasm", &bytesRead);

  if (bytesRead == 0) {
    pntr_app_log(PNTR_APP_LOG_ERROR, "File not found: main.wasm");
    assetsys_destroy(null0->fs);
    return false;
  }

  unsigned long wasmSize = (unsigned long)bytesRead;

  // OK! virtual FS setup, and wasmBytes/size is loaded

  null0->font = pntr_load_font_default();
  cvector_push_back(null0->fonts, null0->font);

  web49_io_input_t infile = (web49_io_input_t){
      .byte_index = 0,
      .byte_len = wasmSize,
      .byte_buf = wasmBytes,
  };

  web49_module_t mod = web49_readbin_module(&infile);

  return true;
}

bool Update(pntr_app* app, pntr_image* screen) {
  // a bit jenk, but I am sharing with the web49 functions
  null0->screen = screen;
  null0->app = app;

  pntr_clear_background(screen, PNTR_RAYWHITE);
  pntr_draw_text(screen, null0->font, "HELLO!", 140, 110, PNTR_DARKGRAY);

  return true;
}

void Close(pntr_app* app) {
  pntr_unload_font(null0->font);
  pntr_unload_memory(null0);
}

pntr_app Main(int argc, char* argv[]) {
#ifdef PNTR_APP_RAYLIB
  SetTraceLogLevel(LOG_WARNING);
#endif

  cartName = argv[1];

  return (pntr_app){
      .width = 320,
      .height = 240,
      .title = "null0",
      .init = Init,
      .update = Update,
      .close = Close,
      .fps = 60};
}
