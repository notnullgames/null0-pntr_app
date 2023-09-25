// TOOD: I probly don't need all these

#include <dirent.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <unistd.h>

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef float f32;

unsigned char* null0_load_file(const char* fname, unsigned int* bytesRead) {
  if (null0 == NULL || null0->fs == NULL || fname == NULL) {
    pntr_app_log(PNTR_APP_LOG_ERROR, "Stuff not set.");
    return NULL;
  }

  char path[1024];

  if (fname[0] == '/') {
    snprintf(path, sizeof(path), "%s%s", "/cart", fname);
  } else {
    snprintf(path, sizeof(path), "%s%s", "/cart/", fname);
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
