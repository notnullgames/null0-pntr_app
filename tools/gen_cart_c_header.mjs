// this will generate the cart-side header
// WARNING: it will overwrite any hand-made changes

import { readFile, writeFile } from 'fs/promises'
import YAML from 'yaml'

const api = YAML.parse(await readFile('tools/api.yml', 'utf8'))

let out = `// This is the C cart-header for null0

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define NULL0_EXPORT(n) __attribute__((export_name(n)))
#define NULL0_IMPORT(n) __attribute__((import_module("null0"), import_name(n)))

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef float f32;

#define RGBA(r, g, b, a) (u32)(r << 24 | g << 16 | b << 8 | a)

#define LIGHTGRAY RGBA(200, 200, 200, 255)
#define GRAY RGBA(130, 130, 130, 255)
#define DARKGRAY RGBA(80, 80, 80, 255)
#define YELLOW RGBA(253, 249, 0, 255)
#define GOLD RGBA(255, 203, 0, 255)
#define ORANGE RGBA(255, 161, 0, 255)
#define PINK RGBA(255, 109, 194, 255)
#define RED RGBA(230, 41, 55, 255)
#define MAROON RGBA(190, 33, 55, 255)
#define GREEN RGBA(0, 228, 48, 255)
#define LIME RGBA(0, 158, 47, 255)
#define DARKGREEN RGBA(0, 117, 44, 255)
#define SKYBLUE RGBA(102, 191, 255, 255)
#define BLUE RGBA(0, 121, 241, 255)
#define DARKBLUE RGBA(0, 82, 172, 255)
#define PURPLE RGBA(200, 122, 255, 255)
#define VIOLET RGBA(135, 60, 190, 255)
#define DARKPURPLE RGBA(112, 31, 126, 255)
#define BEIGE RGBA(211, 176, 131, 255)
#define BROWN RGBA(127, 106, 79, 255)
#define DARKBROWN RGBA(76, 63, 47, 255)
#define WHITE RGBA(255, 255, 255, 255)
#define BLACK RGBA(0, 0, 0, 255)
#define BLANK RGBA(0, 0, 0, 0)
#define MAGENTA RGBA(255, 0, 255, 255)
#define RAYWHITE RGBA(245, 245, 245, 255)

typedef enum Filter {
  FILTER_NEARESTNEIGHBOR = 0,
  FILTER_BILINEAR,
  FILTER_SMOOTH
} Filter;

typedef enum Key {
  KEY_INVALID          = 0,
  KEY_FIRST            = 32,
  KEY_SPACE            = 32,
  KEY_APOSTROPHE       = 39,
  KEY_COMMA            = 44,
  KEY_MINUS            = 45,
  KEY_PERIOD           = 46,
  KEY_SLASH            = 47,
  KEY_0                = 48,
  KEY_1                = 49,
  KEY_2                = 50,
  KEY_3                = 51,
  KEY_4                = 52,
  KEY_5                = 53,
  KEY_6                = 54,
  KEY_7                = 55,
  KEY_8                = 56,
  KEY_9                = 57,
  KEY_SEMICOLON        = 59,
  KEY_EQUAL            = 61,
  KEY_A                = 65,
  KEY_B                = 66,
  KEY_C                = 67,
  KEY_D                = 68,
  KEY_E                = 69,
  KEY_F                = 70,
  KEY_G                = 71,
  KEY_H                = 72,
  KEY_I                = 73,
  KEY_J                = 74,
  KEY_K                = 75,
  KEY_L                = 76,
  KEY_M                = 77,
  KEY_N                = 78,
  KEY_O                = 79,
  KEY_P                = 80,
  KEY_Q                = 81,
  KEY_R                = 82,
  KEY_S                = 83,
  KEY_T                = 84,
  KEY_U                = 85,
  KEY_V                = 86,
  KEY_W                = 87,
  KEY_X                = 88,
  KEY_Y                = 89,
  KEY_Z                = 90,
  KEY_LEFT_BRACKET     = 91,
  KEY_BACKSLASH        = 92,
  KEY_RIGHT_BRACKET    = 93,
  KEY_GRAVE_ACCENT     = 96,
  KEY_WORLD_1          = 161,
  KEY_WORLD_2          = 162,
  KEY_ESCAPE           = 256,
  KEY_ENTER            = 257,
  KEY_TAB              = 258,
  KEY_BACKSPACE        = 259,
  KEY_INSERT           = 260,
  KEY_DELETE           = 261,
  KEY_RIGHT            = 262,
  KEY_LEFT             = 263,
  KEY_DOWN             = 264,
  KEY_UP               = 265,
  KEY_PAGE_UP          = 266,
  KEY_PAGE_DOWN        = 267,
  KEY_HOME             = 268,
  KEY_END              = 269,
  KEY_CAPS_LOCK        = 280,
  KEY_SCROLL_LOCK      = 281,
  KEY_NUM_LOCK         = 282,
  KEY_PRINT_SCREEN     = 283,
  KEY_PAUSE            = 284,
  KEY_F1               = 290,
  KEY_F2               = 291,
  KEY_F3               = 292,
  KEY_F4               = 293,
  KEY_F5               = 294,
  KEY_F6               = 295,
  KEY_F7               = 296,
  KEY_F8               = 297,
  KEY_F9               = 298,
  KEY_F10              = 299,
  KEY_F11              = 300,
  KEY_F12              = 301,
  KEY_F13              = 302,
  KEY_F14              = 303,
  KEY_F15              = 304,
  KEY_F16              = 305,
  KEY_F17              = 306,
  KEY_F18              = 307,
  KEY_F19              = 308,
  KEY_F20              = 309,
  KEY_F21              = 310,
  KEY_F22              = 311,
  KEY_F23              = 312,
  KEY_F24              = 313,
  KEY_F25              = 314,
  KEY_KP_0             = 320,
  KEY_KP_1             = 321,
  KEY_KP_2             = 322,
  KEY_KP_3             = 323,
  KEY_KP_4             = 324,
  KEY_KP_5             = 325,
  KEY_KP_6             = 326,
  KEY_KP_7             = 327,
  KEY_KP_8             = 328,
  KEY_KP_9             = 329,
  KEY_KP_DECIMAL       = 330,
  KEY_KP_DIVIDE        = 331,
  KEY_KP_MULTIPLY      = 332,
  KEY_KP_SUBTRACT      = 333,
  KEY_KP_ADD           = 334,
  KEY_KP_ENTER         = 335,
  KEY_KP_EQUAL         = 336,
  KEY_LEFT_SHIFT       = 340,
  KEY_LEFT_CONTROL     = 341,
  KEY_LEFT_ALT         = 342,
  KEY_LEFT_SUPER       = 343,
  KEY_RIGHT_SHIFT      = 344,
  KEY_RIGHT_CONTROL    = 345,
  KEY_RIGHT_ALT        = 346,
  KEY_RIGHT_SUPER      = 347,
  KEY_MENU             = 348,
  KEY_LAST
} Key;

typedef enum GamepadButton {
    GAMEPAD_BUTTON_UNKNOWN = 0,        // Unknown button, just for error checking
    GAMEPAD_BUTTON_FIRST = 1,
    GAMEPAD_BUTTON_UP = 1,             // Gamepad left DPAD up button
    GAMEPAD_BUTTON_RIGHT,              // Gamepad left DPAD right button
    GAMEPAD_BUTTON_DOWN,               // Gamepad left DPAD down button
    GAMEPAD_BUTTON_LEFT,               // Gamepad left DPAD left button
    GAMEPAD_BUTTON_Y,                  // Gamepad right button up (i.e. PS3: Triangle, Xbox: Y)
    GAMEPAD_BUTTON_B,                  // Gamepad right button right (i.e. PS3: Square, Xbox: X)
    GAMEPAD_BUTTON_A,                  // Gamepad right button down (i.e. PS3: Cross, Xbox: A)
    GAMEPAD_BUTTON_X,                  // Gamepad right button left (i.e. PS3: Circle, Xbox: B)
    GAMEPAD_BUTTON_LEFT_SHOULDER,      // Gamepad top/back trigger left (first), it could be a trailing button
    GAMEPAD_BUTTON_LEFT_TRIGGER,       // Gamepad top/back trigger left (second), it could be a trailing button
    GAMEPAD_BUTTON_RIGHT_SHOULDER,     // Gamepad top/back trigger right (one), it could be a trailing button
    GAMEPAD_BUTTON_RIGHT_TRIGGER,      // Gamepad top/back trigger right (second), it could be a trailing button
    GAMEPAD_BUTTON_SELECT,             // Gamepad center buttons, left one (i.e. PS3: Select)
    GAMEPAD_BUTTON_MENU,               // Gamepad center buttons, middle one (i.e. PS3: PS, Xbox: XBOX)
    GAMEPAD_BUTTON_START,              // Gamepad center buttons, right one (i.e. PS3: Start)
    GAMEPAD_BUTTON_LEFT_THUMB,         // Gamepad joystick pressed button left
    GAMEPAD_BUTTON_RIGHT_THUMB,        // Gamepad joystick pressed button right
    GAMEPAD_BUTTON_LAST
} GamepadButton;

typedef enum MouseButton {
  MOUSE_BUTTON_UNKNOWN = 0,
  MOUSE_BUTTON_FIRST = 1,
  MOUSE_BUTTON_LEFT = 1,
  MOUSE_BUTTON_RIGHT = 2,
  MOUSE_BUTTON_MIDDLE = 3,
  MOUSE_BUTTON_LAST
} MouseButton;

typedef struct ImageDimensions {
  u16 width;
  u16 height;
} ImageDimensions;

typedef struct Vector {
  i32 x;
  i32 y;
} Vector;

typedef struct Rectangle {
  i32 x;
  i32 y;
  i32 width;
  i32 height;
} Rectangle;

#define WIDTH 320
#define HEIGHT 240

`

const typeMap = {
  pntr_color: 'u32',
  'pntr_image*': 'u32',
  'pntr_vector*': 'Vector*',
  'pntr_font*': 'u32',
  pntr_filter: 'Filter',
  pntr_rectangle: 'Rectangle',
  'pntr_rectangle*': 'Rectangle*',
  'pntr_sound*': 'u32',
  pntr_app_key: 'Key',
  pntr_app_gamepad_button: 'GamepadButton',
  pntr_app_mouse_button: 'MouseButton'
}

for (const name of Object.keys(api)) {
  const func = { name, ...api[name] }

  out += `
NULL0_IMPORT("${func.name}")
${typeMap[func.returns] || func.returns} ${func.name}(${Object.keys(func.args).map(n => `${typeMap[func.args[n]] || func.args[n]} ${n}`).join(', ')});
`
}

await writeFile('cart/null0.h', out)
