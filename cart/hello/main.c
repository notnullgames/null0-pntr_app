#include "null0.h"
#include "stdio.h"

f32 w = 0;

int main() {
  // width for centered text
  w = (WIDTH / 2) - (measure_text(0, "Hello from null0") / 2);
  return 0;
}

NULL0_EXPORT("update")
void update(u32 t) {
  clear(BLACK);
  draw_text(0, "Hello from null0", w + 1, (HEIGHT / 2) + 1, BLUE);
  draw_text(0, "Hello from null0", w, HEIGHT / 2, RED);
}
