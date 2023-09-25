// This is the C cart-header for null0

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

#define RGBA(a, r, g, b) (u32)(b << 24 | g << 16 | r << 8 | a)

#define LIGHTGRAY RGBA(200, 200, 200, 255)  // Light Gray
#define GRAY RGBA(130, 130, 130, 255)       // Gray
#define DARKGRAY RGBA(80, 80, 80, 255)      // Dark Gray
#define YELLOW RGBA(253, 249, 0, 255)       // Yellow
#define GOLD RGBA(255, 203, 0, 255)         // Gold
#define ORANGE RGBA(255, 161, 0, 255)       // Orange
#define PINK RGBA(255, 109, 194, 255)       // Pink
#define RED RGBA(230, 41, 55, 255)          // Red
#define MAROON RGBA(190, 33, 55, 255)       // Maroon
#define GREEN RGBA(0, 228, 48, 255)         // Green
#define LIME RGBA(0, 158, 47, 255)          // Lime
#define DARKGREEN RGBA(0, 117, 44, 255)     // Dark Green
#define SKYBLUE RGBA(102, 191, 255, 255)    // Sky Blue
#define BLUE RGBA(0, 121, 241, 255)         // Blue
#define DARKBLUE RGBA(0, 82, 172, 255)      // Dark Blue
#define PURPLE RGBA(200, 122, 255, 255)     // Purple
#define VIOLET RGBA(135, 60, 190, 255)      // Violet
#define DARKPURPLE RGBA(112, 31, 126, 255)  // Dark Purple
#define BEIGE RGBA(211, 176, 131, 255)      // Beige
#define BROWN RGBA(127, 106, 79, 255)       // Brown
#define DARKBROWN RGBA(76, 63, 47, 255)     // Dark Brown
#define WHITE RGBA(255, 255, 255, 255)      // White
#define BLACK RGBA(0, 0, 0, 255)            // Black
#define BLANK RGBA(0, 0, 0, 0)              // Blank (Transparent)
#define MAGENTA RGBA(255, 0, 255, 255)      // Magenta
#define RAYWHITE RGBA(245, 245, 245, 255)   // (raylib logo white)

typedef enum Null0Button {
  BUTTON_A,
  BUTTON_B,
  BUTTON_X,
  BUTTON_Y,
  BUTTON_START,
  BUTTON_SELECT,
  BUTTON_L,
  BUTTON_R,
  BUTTON_UP,
  BUTTON_DOWN,
  BUTTON_LEFT,
  BUTTON_RIGHT
} Null0Button;

typedef enum Filter {
  PNTR_FILTER_NEARESTNEIGHBOR = 0,
  PNTR_FILTER_BILINEAR,
  PNTR_FILTER_SMOOTH
} Filter;

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

// Clear the screen with a color
NULL0_IMPORT("clear")
void clear(u32 color);

// Draw a pixel.
NULL0_IMPORT("draw_pixel")
void draw_pixel(i16 x, i16 y, u32 color);

// Draw rectangle outline.
NULL0_IMPORT("draw_box_outline")
void draw_box_outline(i16 x1, i16 y1, i16 x2, i16 y2, u32 color);

// Draw rounded-corner rectangle outline.
NULL0_IMPORT("draw_rounded_box_outline")
void draw_rounded_box_outline(i16 x1, i16 y1, i16 x2, i16 y2, i16 rad, u32 color);

// Draw filled rectangle.
NULL0_IMPORT("draw_box")
void draw_box(i16 x1, i16 y1, i16 x2, i16 y2, u32 color);

// Draw rounded-corner rectangle.
NULL0_IMPORT("draw_rounded_box")
void draw_rounded_box(i16 x1, i16 y1, i16 x2, i16 y2, i16 rad, u32 color);

// Draw anti-aliased line.
NULL0_IMPORT("draw_line")
void draw_line(i16 x1, i16 y1, i16 x2, i16 y2, u32 color);

// Draw an arc.
NULL0_IMPORT("draw_arc")
void draw_arc(i16 x, i16 y, i16 rad, i16 start, i16 end, u32 color);

// Draw anti-aliased circle outline.
NULL0_IMPORT("draw_circle_outline")
void draw_circle_outline(i16 x, i16 y, i16 rad, u32 color);

// Draw filled circle.
NULL0_IMPORT("draw_circle")
void draw_circle(i16 x, i16 y, i16 rad, u32 color);

// Draw anti-aliased ellipse.
NULL0_IMPORT("draw_ellipse_outline")
void draw_ellipse_outline(i16 x, i16 y, i16 rx, i16 ry, u32 color);

// Draw filled ellipse.
NULL0_IMPORT("draw_ellipse")
void draw_ellipse(i16 x, i16 y, i16 rx, i16 ry, u32 color);

// Draw anti-aliased polygon outline.
NULL0_IMPORT("draw_polygon_outline")
void draw_polygon_outline(i16* vx, i16* vy, u32 n, u32 color);

// Draw filled polygon.
NULL0_IMPORT("draw_polygon")
void draw_polygon(i16* vx, i16* vy, u32 n, u32 color);

// Draw a string in the currently set font.
NULL0_IMPORT("draw_text")
void draw_text(i16 x, i16 y, char* s, u32 color);

// Draw an image
NULL0_IMPORT("draw_image")
void draw_image(u32 image, i16 x, i16 y);

// Draw a part of an image (can be used to scale or draw a sprite) with rotation
NULL0_IMPORT("draw_image_sub")
void draw_image_sub(u32 image, u16 sx, u16 sy, u16 sw, u16 sh, u16 dx, u16 dy, u16 dw, u16 dh, u16 rotation);

// Load a font from the filesystem
NULL0_IMPORT("font_load")
u32 font_load(char* filename);

// Sets the current global font.
NULL0_IMPORT("font_use")
void font_use(u32 font, u32 size);

// Get the width of some text, using current global font.
NULL0_IMPORT("font_measure")
f32 font_measure(char* text);

// undefined
NULL0_IMPORT("image_measure")
ImageDimensions* image_measure(u32 image);

// Load an image from the filesystem
NULL0_IMPORT("image_load")
u32 image_load(char* filename);

// Load a sound
NULL0_IMPORT("sound_load")
u32 sound_load(char* filename);

// Play a sound
NULL0_IMPORT("sound_play")
void sound_play(u32 sound);

// Stop a sound
NULL0_IMPORT("sound_stop")
void sound_stop(u32 sound);
