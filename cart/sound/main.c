#include <stdio.h>
#include "null0.h"

u32 bd;
u32 sd;
u32 ch;
u32 oh;

f32 w1 = 0;
f32 w2 = 0;

int main() {
  bd = sound_load("assets/BD.ogg");
  sd = sound_load("assets/SD.ogg");
  ch = sound_load("assets/CH.ogg");
  oh = sound_load("assets/OH.ogg");

  w1 = font_measure("Press a button");
  w2 = font_measure("on web, you must click win first");
  return 0;
}

NULL0_EXPORT("buttonDown")
void buttonDown(u8 button) {
  if (button == BUTTON_A) {
    sound_play(bd);
  }
  if (button == BUTTON_B) {
    sound_play(sd);
  }
  if (button == BUTTON_X) {
    sound_play(ch);
  }
  if (button == BUTTON_Y) {
    sound_play(oh);
  }
}

NULL0_EXPORT("update")
void update(u32 t) {
  clear(BLANK);
  draw_text((WIDTH / 2) - (w1 / 2), (HEIGHT / 2) - 8, "Press a button", WHITE);
  draw_text((WIDTH / 2) - (w2 / 2), (HEIGHT / 2) + 8, "on web, you must click win first", YELLOW);
}