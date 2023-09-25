#include <stdio.h>
#include "null0.h"

u32 bd;
u32 sd;
u32 ch;
u32 oh;

f32 w1 = 0;
f32 w2 = 0;

int main() {
  bd = load_sound("assets/BD.ogg");
  sd = load_sound("assets/SD.ogg");
  ch = load_sound("assets/CH.ogg");
  oh = load_sound("assets/OH.ogg");

  w1 = measure_text(0, "Press a button");
  w2 = measure_text(0, "on web, you must click win first");
  return 0;
}

NULL0_EXPORT("buttonDown")
void buttonDown(GamepadButton button) {
  if (button == GAMEPAD_BUTTON_A) {
    play_sound(bd, false);
  }
  if (button == GAMEPAD_BUTTON_B) {
    play_sound(sd, false);
  }
  if (button == GAMEPAD_BUTTON_X) {
    play_sound(ch, false);
  }
  if (button == GAMEPAD_BUTTON_Y) {
    play_sound(oh, false);
  }
}

NULL0_EXPORT("update")
void update(u32 t) {
  clear(BLANK);
  draw_text(0, "Press a button", (WIDTH / 2) - (w1 / 2), (HEIGHT / 2) - 8, WHITE);
  draw_text(0, "on web, you must click win first", (WIDTH / 2) - (w2 / 2), (HEIGHT / 2) + 8, YELLOW);
}
