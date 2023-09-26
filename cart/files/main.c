#include <null0.h>

int main() {
  trace("Hello from files.");
  const char* text = load_file_text("assets/cyberpunk.txt");
  trace(text);

  return 0;
}
