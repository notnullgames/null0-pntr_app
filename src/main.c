unsigned char* null0_load_file(const char* path, unsigned int* bytesRead);

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

#include "null0_utils.h"
#include "null0_wasm.h"

web49_env_func_t web49_main_import_func(void* state, const char* mod, const char* func) {
  if (strcmp(mod, "null0") == 0) {
    return web49_api_null0(state, mod, func);
  }
  // else if (strcmp(mod, "wasi_snapshot_preview1") == 0) {
  //   return web49_api_wasi(state, mod, func);
  // }
  fprintf(stderr, "Unhandled import: %s.%s\n", mod, func);
  return NULL;
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
  unsigned char* wasmBytes = null0_load_file("/main.wasm", &bytesRead);

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

  web49_section_import_t imports = web49_module_get_section(mod, WEB49_SECTION_ID_IMPORT).import_section;
  for (size_t j = 0; j < imports.num_entries; j++) {
    web49_section_import_entry_t entry = imports.entries[j];
    // printf("import: %s.%s\n", entry.module_str, entry.field_str);
  }

  web49_section_export_t exports = web49_module_get_section(mod, WEB49_SECTION_ID_EXPORT).export_section;
  for (size_t j = 0; j < exports.num_entries; j++) {
    web49_section_export_entry_t entry = exports.entries[j];
    // printf("export: %s\n", entry.field_str);
    if (strcmp(entry.field_str, "load") == 0 || strcmp(entry.field_str, "_start") == 0) {
      null0->cart_load = entry.index;
    } else if (strcmp(entry.field_str, "update") == 0) {
      null0->cart_update = entry.index;
    }
  }

  web49_opt_tee_module(&mod);
  web49_opt_tree_module(&mod);

  web49_interp_t interp = web49_interp_module(mod);
  web49_interp_add_import_func(&interp, NULL, web49_main_import_func);

  if (null0->cart_load) {
    web49_interp_block_run(&interp, &interp.funcs[null0->cart_load]);
  } else {
    printf("no load function.\n");
  }

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
