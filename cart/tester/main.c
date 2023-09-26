// the purpose of this is to call every API function

#include "null0.h"

u32 logo;
u32 sound;

int main() {
  u32 iBlank = new_image(100, 100, GREEN);
  u32 iCopy = image_copy(iBlank);

  logo = load_image("assets/logo.png");
  sound = load_sound("assets/notnullgames.ogg");

  return 0;
}

NULL0_EXPORT("update")
void update() {
  clear(BLACK);
  draw_image(logo, 100, 100);
}

NULL0_EXPORT("buttonUp")
void buttonUp(GamepadButton button) {
  trace("buttonUp");
}

NULL0_EXPORT("buttonDown")
void buttonDown(GamepadButton button) {
  trace("buttonDown");
}

NULL0_EXPORT("keyUp")
void keyUp(Key key) {
  trace("keyUp");
}

NULL0_EXPORT("keyDown")
void keyDown(Key key) {
  trace("keyDown");
}