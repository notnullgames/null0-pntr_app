#include "null0.h"

f32 w = 0;

int main() {
  // width for centered text
  w = (WIDTH / 2) - font_measure("Hello from null0") / 2;
}

NULL0_EXPORT("update")
void update(u32 t) {
  clear(BLANK);
  draw_text(w + 1, (HEIGHT / 2) + 1, "Hello from null0", DARKBLUE);
  draw_text(w, HEIGHT / 2, "Hello from null0", RED);
}