#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main() {
  char* filename = "assets/cyberpunk.txt";
  // get file info
  struct stat st;
  stat(filename, &st);
  printf("Filesize: %llu\n", st.st_size);

  char buffer[1024];
  char *text = NULL;
  size_t text_size = 0;

  // Open the file for reading
  FILE *file = fopen(filename, "r");
  
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  while (fgets(buffer, sizeof(buffer), file) != NULL) {
    text_size += strlen(buffer);
    text = realloc(text, text_size + 1);
    if (text == NULL) {
      perror("Memory allocation failed");
      return 1;
    }
    strcat(text, buffer);
  }

  fclose(file);

  if (text != NULL) {
    printf("Read text:\n%s", text);
    free(text);
  }

  return 0;
}
