// Null0 web49 host-bindings generated at 2023-09-26T16:47:39.374Z

void null0_clear_screen(pntr_color color) {
  pntr_clear_background(null0->screen, color);
}

u32 null0_add_image(pntr_image* image) {
  cvector_push_back(null0->images, image);
  return cvector_size(null0->images) - 1;
}

u32 null0_add_font(pntr_font* font) {
  cvector_push_back(null0->fonts, font);
  return cvector_size(null0->fonts) - 1;
}

u32 null0_add_sound(pntr_sound* sound) {
  cvector_push_back(null0->sounds, sound);
  return cvector_size(null0->sounds) - 1;
}

pntr_vector* null0_mouse_position(){
  // TODO
}

static web49_interp_data_t wasmimport_new_image(void* wasi_untyped, web49_interp_t interp) {
  
  i32 width = interp.locals[0].i32_s;
  i32 height = interp.locals[1].i32_s;
  pntr_color color = pntr_get_color(interp.locals[2].i32_u);

  return (web49_interp_data_t){.i32_u = null0_add_image(pntr_gen_image_color(width, height, color))};
}

static web49_interp_data_t wasmimport_image_copy(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* image = null0->images[ interp.locals[0].i32_u ];

  return (web49_interp_data_t){.i32_u = null0_add_image(pntr_image_copy(image))};
}

static web49_interp_data_t wasmimport_image_subimage(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* image = null0->images[ interp.locals[0].i32_u ];
  i32 x = interp.locals[1].i32_s;
  i32 y = interp.locals[2].i32_s;
  i32 width = interp.locals[3].i32_s;
  i32 height = interp.locals[4].i32_s;

  return (web49_interp_data_t){.i32_u = null0_add_image(pntr_image_subimage(image, x, y, width, height))};
}

static web49_interp_data_t wasmimport_clear(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_color color = pntr_get_color(interp.locals[0].i32_u);


  null0_clear_screen(color);
  return (web49_interp_data_t){.i32_u = 0};
  
}

static web49_interp_data_t wasmimport_clear_image(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* image = null0->images[ interp.locals[0].i32_u ];
  pntr_color color = pntr_get_color(interp.locals[1].i32_u);


  pntr_clear_background(image, color);
  return (web49_interp_data_t){.i32_u = 0};
  
}

static web49_interp_data_t wasmimport_draw_point(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* dst = null0->screen;
  i32 x = interp.locals[0].i32_s;
  i32 y = interp.locals[1].i32_s;
  pntr_color color = pntr_get_color(interp.locals[2].i32_u);


  pntr_draw_point(dst, x, y, color);
  return (web49_interp_data_t){.i32_u = 0};
  
}

static web49_interp_data_t wasmimport_draw_line(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* dst = null0->screen;
  i32 startPosX = interp.locals[0].i32_s;
  i32 startPosY = interp.locals[1].i32_s;
  i32 endPosX = interp.locals[2].i32_s;
  i32 endPosY = interp.locals[3].i32_s;
  pntr_color color = pntr_get_color(interp.locals[4].i32_u);


  pntr_draw_line(dst, startPosX, startPosY, endPosX, endPosY, color);
  return (web49_interp_data_t){.i32_u = 0};
  
}

static web49_interp_data_t wasmimport_draw_rectangle_outline(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* dst = null0->screen;
  i32 posX = interp.locals[0].i32_s;
  i32 posY = interp.locals[1].i32_s;
  i32 width = interp.locals[2].i32_s;
  i32 height = interp.locals[3].i32_s;
  i32 thickness = interp.locals[4].i32_s;
  pntr_color color = pntr_get_color(interp.locals[5].i32_u);


  pntr_draw_rectangle(dst, posX, posY, width, height, thickness, color);
  return (web49_interp_data_t){.i32_u = 0};
  
}

static web49_interp_data_t wasmimport_draw_rectangle(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* dst = null0->screen;
  i32 posX = interp.locals[0].i32_s;
  i32 posY = interp.locals[1].i32_s;
  i32 width = interp.locals[2].i32_s;
  i32 height = interp.locals[3].i32_s;
  pntr_color color = pntr_get_color(interp.locals[4].i32_u);


  pntr_draw_rectangle_fill(dst, posX, posY, width, height, color);
  return (web49_interp_data_t){.i32_u = 0};
  
}

static web49_interp_data_t wasmimport_draw_triangle_outline(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* dst = null0->screen;
  i32 x1 = interp.locals[0].i32_s;
  i32 y1 = interp.locals[1].i32_s;
  i32 x2 = interp.locals[2].i32_s;
  i32 y2 = interp.locals[3].i32_s;
  i32 x3 = interp.locals[4].i32_s;
  i32 y3 = interp.locals[5].i32_s;
  pntr_color color = pntr_get_color(interp.locals[6].i32_u);


  pntr_draw_triangle(dst, x1, y1, x2, y2, x3, y3, color);
  return (web49_interp_data_t){.i32_u = 0};
  
}

static web49_interp_data_t wasmimport_draw_triangle(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* dst = null0->screen;
  i32 x1 = interp.locals[0].i32_s;
  i32 y1 = interp.locals[1].i32_s;
  i32 x2 = interp.locals[2].i32_s;
  i32 y2 = interp.locals[3].i32_s;
  i32 x3 = interp.locals[4].i32_s;
  i32 y3 = interp.locals[5].i32_s;
  pntr_color color = pntr_get_color(interp.locals[6].i32_u);


  pntr_draw_triangle_fill(dst, x1, y1, x2, y2, x3, y3, color);
  return (web49_interp_data_t){.i32_u = 0};
  
}

static web49_interp_data_t wasmimport_draw_ellipse_outline(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* dst = null0->screen;
  i32 centerX = interp.locals[0].i32_s;
  i32 centerY = interp.locals[1].i32_s;
  i32 radiusX = interp.locals[2].i32_s;
  i32 radiusY = interp.locals[3].i32_s;
  pntr_color color = pntr_get_color(interp.locals[4].i32_u);


  pntr_draw_ellipse(dst, centerX, centerY, radiusX, radiusY, color);
  return (web49_interp_data_t){.i32_u = 0};
  
}

static web49_interp_data_t wasmimport_draw_ellipse(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* dst = null0->screen;
  i32 centerX = interp.locals[0].i32_s;
  i32 centerY = interp.locals[1].i32_s;
  i32 radiusX = interp.locals[2].i32_s;
  i32 radiusY = interp.locals[3].i32_s;
  pntr_color color = pntr_get_color(interp.locals[4].i32_u);


  pntr_draw_ellipse_fill(dst, centerX, centerY, radiusX, radiusY, color);
  return (web49_interp_data_t){.i32_u = 0};
  
}

static web49_interp_data_t wasmimport_draw_circle_outline(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* dst = null0->screen;
  i32 centerX = interp.locals[0].i32_s;
  i32 centerY = interp.locals[1].i32_s;
  i32 radius = interp.locals[2].i32_s;
  pntr_color color = pntr_get_color(interp.locals[3].i32_u);


  pntr_draw_circle(dst, centerX, centerY, radius, color);
  return (web49_interp_data_t){.i32_u = 0};
  
}

static web49_interp_data_t wasmimport_draw_circle(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* dst = null0->screen;
  i32 centerX = interp.locals[0].i32_s;
  i32 centerY = interp.locals[1].i32_s;
  i32 radius = interp.locals[2].i32_s;
  pntr_color color = pntr_get_color(interp.locals[3].i32_u);


  pntr_draw_circle_fill(dst, centerX, centerY, radius, color);
  return (web49_interp_data_t){.i32_u = 0};
  
}

static web49_interp_data_t wasmimport_draw_polygon_outline(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* dst = null0->screen;
  pntr_vector* points = (pntr_vector*) interp.memory[interp.locals[0].i32_u];
  i32 numPoints = interp.locals[1].i32_s;
  pntr_color color = pntr_get_color(interp.locals[2].i32_u);


  pntr_draw_polygon(dst, points, numPoints, color);
  return (web49_interp_data_t){.i32_u = 0};
  
}

static web49_interp_data_t wasmimport_draw_polygon(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* dst = null0->screen;
  pntr_vector* points = (pntr_vector*) interp.memory[interp.locals[0].i32_u];
  i32 numPoints = interp.locals[1].i32_s;
  pntr_color color = pntr_get_color(interp.locals[2].i32_u);


  pntr_draw_polygon_fill(dst, points, numPoints, color);
  return (web49_interp_data_t){.i32_u = 0};
  
}

static web49_interp_data_t wasmimport_draw_polyline(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* dst = null0->screen;
  pntr_vector* points = (pntr_vector*) interp.memory[interp.locals[0].i32_u];
  i32 numPoints = interp.locals[1].i32_s;
  pntr_color color = pntr_get_color(interp.locals[2].i32_u);


  pntr_draw_polyline(dst, points, numPoints, color);
  return (web49_interp_data_t){.i32_u = 0};
  
}

static web49_interp_data_t wasmimport_draw_arc_outline(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* dst = null0->screen;
  i32 centerX = interp.locals[0].i32_s;
  i32 centerY = interp.locals[1].i32_s;
  f32 radius = interp.locals[2].f32;
  f32 startAngle = interp.locals[3].f32;
  f32 endAngle = interp.locals[4].f32;
  i32 segments = interp.locals[5].i32_s;
  pntr_color color = pntr_get_color(interp.locals[6].i32_u);


  pntr_draw_arc(dst, centerX, centerY, radius, startAngle, endAngle, segments, color);
  return (web49_interp_data_t){.i32_u = 0};
  
}

static web49_interp_data_t wasmimport_draw_arc(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* dst = null0->screen;
  i32 centerX = interp.locals[0].i32_s;
  i32 centerY = interp.locals[1].i32_s;
  f32 radius = interp.locals[2].f32;
  f32 startAngle = interp.locals[3].f32;
  f32 endAngle = interp.locals[4].f32;
  i32 segments = interp.locals[5].i32_s;
  pntr_color color = pntr_get_color(interp.locals[6].i32_u);


  pntr_draw_arc_fill(dst, centerX, centerY, radius, startAngle, endAngle, segments, color);
  return (web49_interp_data_t){.i32_u = 0};
  
}

static web49_interp_data_t wasmimport_draw_rectangle_rounded_outline(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* dst = null0->screen;
  i32 x = interp.locals[0].i32_s;
  i32 y = interp.locals[1].i32_s;
  i32 width = interp.locals[2].i32_s;
  i32 height = interp.locals[3].i32_s;
  i32 topLeftRadius = interp.locals[4].i32_s;
  i32 topRightRadius = interp.locals[5].i32_s;
  i32 bottomLeftRadius = interp.locals[6].i32_s;
  i32 bottomRightRadius = interp.locals[7].i32_s;
  pntr_color color = pntr_get_color(interp.locals[8].i32_u);


  pntr_draw_rectangle_rounded(dst, x, y, width, height, topLeftRadius, topRightRadius, bottomLeftRadius, bottomRightRadius, color);
  return (web49_interp_data_t){.i32_u = 0};
  
}

static web49_interp_data_t wasmimport_draw_rectangle_rounded(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* dst = null0->screen;
  i32 x = interp.locals[0].i32_s;
  i32 y = interp.locals[1].i32_s;
  i32 width = interp.locals[2].i32_s;
  i32 height = interp.locals[3].i32_s;
  i32 cornerRadius = interp.locals[4].i32_s;
  pntr_color color = pntr_get_color(interp.locals[5].i32_u);


  pntr_draw_rectangle_rounded_fill(dst, x, y, width, height, cornerRadius, color);
  return (web49_interp_data_t){.i32_u = 0};
  
}

static web49_interp_data_t wasmimport_draw_image(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* dst = null0->screen;
  pntr_image* src = null0->images[ interp.locals[0].i32_u ];
  i32 posX = interp.locals[1].i32_s;
  i32 posY = interp.locals[2].i32_s;


  pntr_draw_image(dst, src, posX, posY);
  return (web49_interp_data_t){.i32_u = 0};
  
}

static web49_interp_data_t wasmimport_draw_image_tint(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* dst = null0->screen;
  pntr_image* src = null0->images[ interp.locals[0].i32_u ];
  i32 posX = interp.locals[1].i32_s;
  i32 posY = interp.locals[2].i32_s;
  pntr_color tint = pntr_get_color(interp.locals[3].i32_u);


  pntr_draw_image_tint(dst, src, posX, posY, tint);
  return (web49_interp_data_t){.i32_u = 0};
  
}

static web49_interp_data_t wasmimport_draw_image_rotated(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* dst = null0->screen;
  pntr_image* src = null0->images[ interp.locals[0].i32_u ];
  i32 posX = interp.locals[1].i32_s;
  i32 posY = interp.locals[2].i32_s;
  f32 degrees = interp.locals[3].f32;
  f32 offsetX = interp.locals[4].f32;
  f32 offsetY = interp.locals[5].f32;
  pntr_filter filter = interp.locals[6].i32_u;


  pntr_draw_image_rotated(dst, src, posX, posY, degrees, offsetX, offsetY, filter);
  return (web49_interp_data_t){.i32_u = 0};
  
}

static web49_interp_data_t wasmimport_draw_image_flipped(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* dst = null0->screen;
  pntr_image* src = null0->images[ interp.locals[0].i32_u ];
  i32 posX = interp.locals[1].i32_s;
  i32 posY = interp.locals[2].i32_s;
  bool flipHorizontal = interp.locals[3].i32_u;
  bool flipVertical = interp.locals[4].i32_u;


  pntr_draw_image_flipped(dst, src, posX, posY, flipHorizontal, flipVertical);
  return (web49_interp_data_t){.i32_u = 0};
  
}

static web49_interp_data_t wasmimport_draw_image_scaled(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* dst = null0->screen;
  pntr_image* src = null0->images[ interp.locals[0].i32_u ];
  i32 posX = interp.locals[1].i32_s;
  i32 posY = interp.locals[2].i32_s;
  f32 scaleX = interp.locals[3].f32;
  f32 scaleY = interp.locals[4].f32;
  f32 offsetX = interp.locals[5].f32;
  f32 offsetY = interp.locals[6].f32;
  pntr_filter filter = interp.locals[7].i32_u;


  pntr_draw_image_scaled(dst, src, posX, posY, scaleX, scaleY, offsetX, offsetY, filter);
  return (web49_interp_data_t){.i32_u = 0};
  
}

static web49_interp_data_t wasmimport_draw_text(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* dst = null0->screen;
  pntr_font* font = null0->fonts[ interp.locals[0].i32_u ];
  char* text = WEB49_INTERP_ADDR(char*, interp, interp.locals[1].i32_u, 0);
  i32 posX = interp.locals[2].i32_s;
  i32 posY = interp.locals[3].i32_s;
  pntr_color color = pntr_get_color(interp.locals[4].i32_u);


  pntr_draw_text(dst, font, text, posX, posY, color);
  return (web49_interp_data_t){.i32_u = 0};
  
}

static web49_interp_data_t wasmimport_save_file(void* wasi_untyped, web49_interp_t interp) {
  
  char* fileName = WEB49_INTERP_ADDR(char*, interp, interp.locals[0].i32_u, 0);
  const void* data = (const void*) interp.memory[interp.locals[1].i32_u];
  unsigned int bytesToWrite = interp.locals[2].i32_u;


  return (web49_interp_data_t){.i32_u = pntr_save_file(fileName, data, bytesToWrite)};
}

static web49_interp_data_t wasmimport_save_image(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* image = null0->images[ interp.locals[0].i32_u ];
  char* fileName = WEB49_INTERP_ADDR(char*, interp, interp.locals[1].i32_u, 0);


  return (web49_interp_data_t){.i32_u = pntr_save_image(image, fileName)};
}

static web49_interp_data_t wasmimport_load_image(void* wasi_untyped, web49_interp_t interp) {
  
  char* fileName = WEB49_INTERP_ADDR(char*, interp, interp.locals[0].i32_u, 0);

  return (web49_interp_data_t){.i32_u = null0_add_image(pntr_load_image(fileName))};
}

static web49_interp_data_t wasmimport_image_resize(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* image = null0->images[ interp.locals[0].i32_u ];
  i32 newWidth = interp.locals[1].i32_s;
  i32 newHeight = interp.locals[2].i32_s;
  i32 offsetX = interp.locals[3].i32_s;
  i32 offsetY = interp.locals[4].i32_s;
  pntr_color fill = pntr_get_color(interp.locals[5].i32_u);


  return (web49_interp_data_t){.i32_u = pntr_image_resize_canvas(image, newWidth, newHeight, offsetX, offsetY, fill)};
}

static web49_interp_data_t wasmimport_image_scale(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* image = null0->images[ interp.locals[0].i32_u ];
  f32 scaleX = interp.locals[1].f32;
  f32 scaleY = interp.locals[2].f32;
  pntr_filter filter = interp.locals[3].i32_u;

  return (web49_interp_data_t){.i32_u = null0_add_image(pntr_image_scale(image, scaleX, scaleY, filter))};
}

static web49_interp_data_t wasmimport_image_color_replace(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* image = null0->images[ interp.locals[0].i32_u ];
  pntr_color color = pntr_get_color(interp.locals[1].i32_u);
  pntr_color replace = pntr_get_color(interp.locals[2].i32_u);


  pntr_image_color_replace(image, color, replace);
  return (web49_interp_data_t){.i32_u = 0};
  
}

static web49_interp_data_t wasmimport_color_tint(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_color color = pntr_get_color(interp.locals[0].i32_u);
  pntr_color tint = pntr_get_color(interp.locals[1].i32_u);

  return (web49_interp_data_t){.i32_u = pntr_color_tint(color, tint).data };
}

static web49_interp_data_t wasmimport_image_color_tint(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* image = null0->images[ interp.locals[0].i32_u ];
  pntr_color color = pntr_get_color(interp.locals[1].i32_u);


  pntr_image_color_tint(image, color);
  return (web49_interp_data_t){.i32_u = 0};
  
}

static web49_interp_data_t wasmimport_color_fade(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_color color = pntr_get_color(interp.locals[0].i32_u);
  f32 alpha = interp.locals[1].f32;

  return (web49_interp_data_t){.i32_u = pntr_color_fade(color, alpha).data };
}

static web49_interp_data_t wasmimport_image_color_fade(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* image = null0->images[ interp.locals[0].i32_u ];
  f32 alpha = interp.locals[1].f32;


  pntr_image_color_fade(image, alpha);
  return (web49_interp_data_t){.i32_u = 0};
  
}

static web49_interp_data_t wasmimport_color_brightness(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_color color = pntr_get_color(interp.locals[0].i32_u);
  f32 factor = interp.locals[1].f32;

  return (web49_interp_data_t){.i32_u = pntr_color_brightness(color, factor).data };
}

static web49_interp_data_t wasmimport_font_copy(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_font* font = null0->fonts[ interp.locals[0].i32_u ];

  return (web49_interp_data_t){.i32_u = null0_add_font(pntr_font_copy(font))};
}

static web49_interp_data_t wasmimport_font_scale(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_font* font = null0->fonts[ interp.locals[0].i32_u ];
  f32 scaleX = interp.locals[1].f32;
  f32 scaleY = interp.locals[2].f32;
  pntr_filter filter = interp.locals[3].i32_u;

  return (web49_interp_data_t){.i32_u = null0_add_font(pntr_font_scale(font, scaleX, scaleY, filter))};
}

static web49_interp_data_t wasmimport_load_font_bmf(void* wasi_untyped, web49_interp_t interp) {
  
  char* fileName = WEB49_INTERP_ADDR(char*, interp, interp.locals[0].i32_u, 0);
  char* characters = WEB49_INTERP_ADDR(char*, interp, interp.locals[1].i32_u, 0);

  return (web49_interp_data_t){.i32_u = null0_add_font(pntr_load_font_bmf(fileName, characters))};
}

static web49_interp_data_t wasmimport_load_font_bmf_from_image(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* image = null0->images[ interp.locals[0].i32_u ];
  char* characters = WEB49_INTERP_ADDR(char*, interp, interp.locals[1].i32_u, 0);

  return (web49_interp_data_t){.i32_u = null0_add_font(pntr_load_font_bmf_from_image(image, characters))};
}

static web49_interp_data_t wasmimport_measure_text(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_font* font = null0->fonts[ interp.locals[0].i32_u ];
  char* text = WEB49_INTERP_ADDR(char*, interp, interp.locals[1].i32_u, 0);


  return (web49_interp_data_t){.i32_s = pntr_measure_text(font, text)};
}

static web49_interp_data_t wasmimport_gen_image_text(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_font* font = null0->fonts[ interp.locals[0].i32_u ];
  char* text = WEB49_INTERP_ADDR(char*, interp, interp.locals[1].i32_u, 0);
  pntr_color tint = pntr_get_color(interp.locals[2].i32_u);

  return (web49_interp_data_t){.i32_u = null0_add_image(pntr_gen_image_text(font, text, tint))};
}

static web49_interp_data_t wasmimport_load_font_tty(void* wasi_untyped, web49_interp_t interp) {
  
  char* fileName = WEB49_INTERP_ADDR(char*, interp, interp.locals[0].i32_u, 0);
  i32 glyphWidth = interp.locals[1].i32_s;
  i32 glyphHeight = interp.locals[2].i32_s;
  char* characters = WEB49_INTERP_ADDR(char*, interp, interp.locals[3].i32_u, 0);

  return (web49_interp_data_t){.i32_u = null0_add_font(pntr_load_font_tty(fileName, glyphWidth, glyphHeight, characters))};
}

static web49_interp_data_t wasmimport_load_font_tty_from_image(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* image = null0->images[ interp.locals[0].i32_u ];
  i32 glyphWidth = interp.locals[1].i32_s;
  i32 glyphHeight = interp.locals[2].i32_s;
  char* characters = WEB49_INTERP_ADDR(char*, interp, interp.locals[3].i32_u, 0);

  return (web49_interp_data_t){.i32_u = null0_add_font(pntr_load_font_tty_from_image(image, glyphWidth, glyphHeight, characters))};
}

static web49_interp_data_t wasmimport_load_file(void* wasi_untyped, web49_interp_t interp) {
  
  char* fileName = WEB49_INTERP_ADDR(char*, interp, interp.locals[0].i32_u, 0);
  unsigned int* bytesRead = (unsigned int*) interp.memory[interp.locals[1].i32_u];

// TODO: return unsigned char*
    pntr_load_file(fileName, bytesRead);
    return (web49_interp_data_t){.i32_u = 0};
}

static web49_interp_data_t wasmimport_load_file_text(void* wasi_untyped, web49_interp_t interp) {
  
  char* fileName = WEB49_INTERP_ADDR(char*, interp, interp.locals[0].i32_u, 0);

// TODO: return const char*
    pntr_load_file_text(fileName);
    return (web49_interp_data_t){.i32_u = 0};
}

static web49_interp_data_t wasmimport_load_font_ttf(void* wasi_untyped, web49_interp_t interp) {
  
  char* fileName = WEB49_INTERP_ADDR(char*, interp, interp.locals[0].i32_u, 0);
  i32 fontSize = interp.locals[1].i32_s;

  return (web49_interp_data_t){.i32_u = null0_add_font(pntr_load_font_ttf(fileName, fontSize))};
}

static web49_interp_data_t wasmimport_color_invert(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_color color = pntr_get_color(interp.locals[0].i32_u);

  return (web49_interp_data_t){.i32_u = pntr_color_invert(color).data };
}

static web49_interp_data_t wasmimport_image_color_invert(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* image = null0->images[ interp.locals[0].i32_u ];


  pntr_image_color_invert(image);
  return (web49_interp_data_t){.i32_u = 0};
  
}

static web49_interp_data_t wasmimport_color_alpha_blend(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_color dst = pntr_get_color(interp.locals[0].i32_u);
  pntr_color src = pntr_get_color(interp.locals[1].i32_u);

  return (web49_interp_data_t){.i32_u = pntr_color_alpha_blend(dst, src).data };
}

static web49_interp_data_t wasmimport_image_alpha_border(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* image = null0->images[ interp.locals[0].i32_u ];
  f32 threshold = interp.locals[1].f32;

// TODO: return pntr_rectangle*
    pntr_image_alpha_border(image, threshold);
    return (web49_interp_data_t){.i32_u = 0};
}

static web49_interp_data_t wasmimport_image_crop(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* image = null0->images[ interp.locals[0].i32_u ];
  i32 x = interp.locals[1].i32_s;
  i32 y = interp.locals[2].i32_s;
  i32 width = interp.locals[3].i32_s;
  i32 height = interp.locals[4].i32_s;


  return (web49_interp_data_t){.i32_u = pntr_image_crop(image, x, y, width, height)};
}

static web49_interp_data_t wasmimport_image_alpha_crop(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* image = null0->images[ interp.locals[0].i32_u ];
  f32 threshold = interp.locals[1].f32;


  pntr_image_alpha_crop(image, threshold);
  return (web49_interp_data_t){.i32_u = 0};
  
}

static web49_interp_data_t wasmimport_image_color_brightness(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* image = null0->images[ interp.locals[0].i32_u ];
  f32 factor = interp.locals[1].f32;


  pntr_image_color_brightness(image, factor);
  return (web49_interp_data_t){.i32_u = 0};
  
}

static web49_interp_data_t wasmimport_image_flip(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* image = null0->images[ interp.locals[0].i32_u ];
  bool horizontal = interp.locals[1].i32_u;
  bool vertical = interp.locals[2].i32_u;


  pntr_image_flip(image, horizontal, vertical);
  return (web49_interp_data_t){.i32_u = 0};
  
}

static web49_interp_data_t wasmimport_color_contrast(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_color color = pntr_get_color(interp.locals[0].i32_u);
  f32 contrast = interp.locals[1].f32;

  return (web49_interp_data_t){.i32_u = pntr_color_contrast(color, contrast).data };
}

static web49_interp_data_t wasmimport_image_color_contrast(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* image = null0->images[ interp.locals[0].i32_u ];
  f32 contrast = interp.locals[1].f32;


  pntr_image_color_contrast(image, contrast);
  return (web49_interp_data_t){.i32_u = 0};
  
}

static web49_interp_data_t wasmimport_image_alpha_mask(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* image = null0->images[ interp.locals[0].i32_u ];
  pntr_image* alphaMask = null0->images[ interp.locals[1].i32_u ];
  i32 posX = interp.locals[2].i32_s;
  i32 posY = interp.locals[3].i32_s;


  pntr_image_alpha_mask(image, alphaMask, posX, posY);
  return (web49_interp_data_t){.i32_u = 0};
  
}

static web49_interp_data_t wasmimport_image_rotate(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_image* image = null0->images[ interp.locals[0].i32_u ];
  f32 degrees = interp.locals[1].f32;
  pntr_filter filter = interp.locals[2].i32_u;

  return (web49_interp_data_t){.i32_u = null0_add_image(pntr_image_rotate(image, degrees, filter))};
}

static web49_interp_data_t wasmimport_image_gradient(void* wasi_untyped, web49_interp_t interp) {
  
  i32 width = interp.locals[0].i32_s;
  i32 height = interp.locals[1].i32_s;
  pntr_color topLeft = pntr_get_color(interp.locals[2].i32_u);
  pntr_color topRight = pntr_get_color(interp.locals[3].i32_u);
  pntr_color bottomLeft = pntr_get_color(interp.locals[4].i32_u);
  pntr_color bottomRight = pntr_get_color(interp.locals[5].i32_u);

  return (web49_interp_data_t){.i32_u = null0_add_image(pntr_gen_image_gradient(width, height, topLeft, topRight, bottomLeft, bottomRight))};
}

static web49_interp_data_t wasmimport_color_bilinear_interpolate(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_color color00 = pntr_get_color(interp.locals[0].i32_u);
  pntr_color color01 = pntr_get_color(interp.locals[1].i32_u);
  pntr_color color10 = pntr_get_color(interp.locals[2].i32_u);
  pntr_color color11 = pntr_get_color(interp.locals[3].i32_u);
  f32 coordinateX = interp.locals[4].f32;
  f32 coordinateY = interp.locals[5].f32;

  return (web49_interp_data_t){.i32_u = pntr_color_bilinear_interpolate(color00, color01, color10, color11, coordinateX, coordinateY).data };
}

static web49_interp_data_t wasmimport_load_sound(void* wasi_untyped, web49_interp_t interp) {
  
  char* fileName = WEB49_INTERP_ADDR(char*, interp, interp.locals[0].i32_u, 0);

  return (web49_interp_data_t){.i32_u = null0_add_sound(pntr_load_sound(fileName))};
}

static web49_interp_data_t wasmimport_play_sound(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_sound* sound = null0->sounds[ interp.locals[0].i32_u ];
  bool loop = interp.locals[1].i32_u;


  pntr_play_sound(sound, loop);
  return (web49_interp_data_t){.i32_u = 0};
  
}

static web49_interp_data_t wasmimport_stop_sound(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_sound* sound = null0->sounds[ interp.locals[0].i32_u ];


  pntr_stop_sound(sound);
  return (web49_interp_data_t){.i32_u = 0};
  
}

static web49_interp_data_t wasmimport_delta_time(void* wasi_untyped, web49_interp_t interp) {
    pntr_app* app = null0->app;


  return (web49_interp_data_t){.f32 = pntr_app_delta_time(app)};
}

static web49_interp_data_t wasmimport_key_pressed(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_app* app = null0->app;
  pntr_app_key key = interp.locals[0].i32_u;


  return (web49_interp_data_t){.i32_u = pntr_app_key_pressed(app, key)};
}

static web49_interp_data_t wasmimport_key_down(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_app* app = null0->app;
  pntr_app_key key = interp.locals[0].i32_u;


  return (web49_interp_data_t){.i32_u = pntr_app_key_down(app, key)};
}

static web49_interp_data_t wasmimport_key_released(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_app* app = null0->app;
  pntr_app_key key = interp.locals[0].i32_u;


  return (web49_interp_data_t){.i32_u = pntr_app_key_released(app, key)};
}

static web49_interp_data_t wasmimport_key_up(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_app* app = null0->app;
  pntr_app_key key = interp.locals[0].i32_u;


  return (web49_interp_data_t){.i32_u = pntr_app_key_up(app, key)};
}

static web49_interp_data_t wasmimport_gamepad_button_pressed(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_app* app = null0->app;
  i32 gamepad = interp.locals[0].i32_s;
  pntr_app_gamepad_button key = interp.locals[1].i32_u;


  return (web49_interp_data_t){.i32_u = pntr_app_gamepad_button_pressed(app, gamepad, key)};
}

static web49_interp_data_t wasmimport_gamepad_button_down(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_app* app = null0->app;
  i32 gamepad = interp.locals[0].i32_s;
  pntr_app_gamepad_button key = interp.locals[1].i32_u;


  return (web49_interp_data_t){.i32_u = pntr_app_gamepad_button_down(app, gamepad, key)};
}

static web49_interp_data_t wasmimport_gamepad_button_released(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_app* app = null0->app;
  i32 gamepad = interp.locals[0].i32_s;
  pntr_app_gamepad_button key = interp.locals[1].i32_u;


  return (web49_interp_data_t){.i32_u = pntr_app_gamepad_button_released(app, gamepad, key)};
}

static web49_interp_data_t wasmimport_gamepad_button_up(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_app* app = null0->app;
  i32 gamepad = interp.locals[0].i32_s;
  pntr_app_gamepad_button key = interp.locals[1].i32_u;


  return (web49_interp_data_t){.i32_u = pntr_app_gamepad_button_up(app, gamepad, key)};
}

static web49_interp_data_t wasmimport_mouse_position(void* wasi_untyped, web49_interp_t interp) {
  // TODO: return pntr_vector*
    null0_mouse_position();
    return (web49_interp_data_t){.i32_u = 0};
}

static web49_interp_data_t wasmimport_mouse_button_pressed(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_app* app = null0->app;
  pntr_app_mouse_button button = interp.locals[0].i32_u;


  return (web49_interp_data_t){.i32_u = pntr_app_mouse_button_pressed(app, button)};
}

static web49_interp_data_t wasmimport_mouse_button_down(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_app* app = null0->app;
  pntr_app_mouse_button button = interp.locals[0].i32_u;


  return (web49_interp_data_t){.i32_u = pntr_app_mouse_button_down(app, button)};
}

static web49_interp_data_t wasmimport_mouse_button_released(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_app* app = null0->app;
  pntr_app_mouse_button button = interp.locals[0].i32_u;


  return (web49_interp_data_t){.i32_u = pntr_app_mouse_button_released(app, button)};
}

static web49_interp_data_t wasmimport_mouse_button_up(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_app* app = null0->app;
  pntr_app_mouse_button button = interp.locals[0].i32_u;


  return (web49_interp_data_t){.i32_u = pntr_app_mouse_button_up(app, button)};
}

static web49_interp_data_t wasmimport_set_title(void* wasi_untyped, web49_interp_t interp) {
  
  pntr_app* app = null0->app;
  char* title = WEB49_INTERP_ADDR(char*, interp, interp.locals[0].i32_u, 0);


  pntr_app_set_title(app, title);
  return (web49_interp_data_t){.i32_u = 0};
  
}

web49_env_func_t web49_api_null0(void* state, const char* mod, const char* func) {
  web49_env_func_t ret = NULL;

  if (!strcmp(mod, "null0")) {
    if (strcmp(func, "new_image") == 0){
      ret = &wasmimport_new_image;
    } else if (strcmp(func, "image_copy") == 0){
      ret = &wasmimport_image_copy;
    } else if (strcmp(func, "image_subimage") == 0){
      ret = &wasmimport_image_subimage;
    } else if (strcmp(func, "clear") == 0){
      ret = &wasmimport_clear;
    } else if (strcmp(func, "clear_image") == 0){
      ret = &wasmimport_clear_image;
    } else if (strcmp(func, "draw_point") == 0){
      ret = &wasmimport_draw_point;
    } else if (strcmp(func, "draw_line") == 0){
      ret = &wasmimport_draw_line;
    } else if (strcmp(func, "draw_rectangle_outline") == 0){
      ret = &wasmimport_draw_rectangle_outline;
    } else if (strcmp(func, "draw_rectangle") == 0){
      ret = &wasmimport_draw_rectangle;
    } else if (strcmp(func, "draw_triangle_outline") == 0){
      ret = &wasmimport_draw_triangle_outline;
    } else if (strcmp(func, "draw_triangle") == 0){
      ret = &wasmimport_draw_triangle;
    } else if (strcmp(func, "draw_ellipse_outline") == 0){
      ret = &wasmimport_draw_ellipse_outline;
    } else if (strcmp(func, "draw_ellipse") == 0){
      ret = &wasmimport_draw_ellipse;
    } else if (strcmp(func, "draw_circle_outline") == 0){
      ret = &wasmimport_draw_circle_outline;
    } else if (strcmp(func, "draw_circle") == 0){
      ret = &wasmimport_draw_circle;
    } else if (strcmp(func, "draw_polygon_outline") == 0){
      ret = &wasmimport_draw_polygon_outline;
    } else if (strcmp(func, "draw_polygon") == 0){
      ret = &wasmimport_draw_polygon;
    } else if (strcmp(func, "draw_polyline") == 0){
      ret = &wasmimport_draw_polyline;
    } else if (strcmp(func, "draw_arc_outline") == 0){
      ret = &wasmimport_draw_arc_outline;
    } else if (strcmp(func, "draw_arc") == 0){
      ret = &wasmimport_draw_arc;
    } else if (strcmp(func, "draw_rectangle_rounded_outline") == 0){
      ret = &wasmimport_draw_rectangle_rounded_outline;
    } else if (strcmp(func, "draw_rectangle_rounded") == 0){
      ret = &wasmimport_draw_rectangle_rounded;
    } else if (strcmp(func, "draw_image") == 0){
      ret = &wasmimport_draw_image;
    } else if (strcmp(func, "draw_image_tint") == 0){
      ret = &wasmimport_draw_image_tint;
    } else if (strcmp(func, "draw_image_rotated") == 0){
      ret = &wasmimport_draw_image_rotated;
    } else if (strcmp(func, "draw_image_flipped") == 0){
      ret = &wasmimport_draw_image_flipped;
    } else if (strcmp(func, "draw_image_scaled") == 0){
      ret = &wasmimport_draw_image_scaled;
    } else if (strcmp(func, "draw_text") == 0){
      ret = &wasmimport_draw_text;
    } else if (strcmp(func, "save_file") == 0){
      ret = &wasmimport_save_file;
    } else if (strcmp(func, "save_image") == 0){
      ret = &wasmimport_save_image;
    } else if (strcmp(func, "load_image") == 0){
      ret = &wasmimport_load_image;
    } else if (strcmp(func, "image_resize") == 0){
      ret = &wasmimport_image_resize;
    } else if (strcmp(func, "image_scale") == 0){
      ret = &wasmimport_image_scale;
    } else if (strcmp(func, "image_color_replace") == 0){
      ret = &wasmimport_image_color_replace;
    } else if (strcmp(func, "color_tint") == 0){
      ret = &wasmimport_color_tint;
    } else if (strcmp(func, "image_color_tint") == 0){
      ret = &wasmimport_image_color_tint;
    } else if (strcmp(func, "color_fade") == 0){
      ret = &wasmimport_color_fade;
    } else if (strcmp(func, "image_color_fade") == 0){
      ret = &wasmimport_image_color_fade;
    } else if (strcmp(func, "color_brightness") == 0){
      ret = &wasmimport_color_brightness;
    } else if (strcmp(func, "font_copy") == 0){
      ret = &wasmimport_font_copy;
    } else if (strcmp(func, "font_scale") == 0){
      ret = &wasmimport_font_scale;
    } else if (strcmp(func, "load_font_bmf") == 0){
      ret = &wasmimport_load_font_bmf;
    } else if (strcmp(func, "load_font_bmf_from_image") == 0){
      ret = &wasmimport_load_font_bmf_from_image;
    } else if (strcmp(func, "measure_text") == 0){
      ret = &wasmimport_measure_text;
    } else if (strcmp(func, "gen_image_text") == 0){
      ret = &wasmimport_gen_image_text;
    } else if (strcmp(func, "load_font_tty") == 0){
      ret = &wasmimport_load_font_tty;
    } else if (strcmp(func, "load_font_tty_from_image") == 0){
      ret = &wasmimport_load_font_tty_from_image;
    } else if (strcmp(func, "load_file") == 0){
      ret = &wasmimport_load_file;
    } else if (strcmp(func, "load_file_text") == 0){
      ret = &wasmimport_load_file_text;
    } else if (strcmp(func, "load_font_ttf") == 0){
      ret = &wasmimport_load_font_ttf;
    } else if (strcmp(func, "color_invert") == 0){
      ret = &wasmimport_color_invert;
    } else if (strcmp(func, "image_color_invert") == 0){
      ret = &wasmimport_image_color_invert;
    } else if (strcmp(func, "color_alpha_blend") == 0){
      ret = &wasmimport_color_alpha_blend;
    } else if (strcmp(func, "image_alpha_border") == 0){
      ret = &wasmimport_image_alpha_border;
    } else if (strcmp(func, "image_crop") == 0){
      ret = &wasmimport_image_crop;
    } else if (strcmp(func, "image_alpha_crop") == 0){
      ret = &wasmimport_image_alpha_crop;
    } else if (strcmp(func, "image_color_brightness") == 0){
      ret = &wasmimport_image_color_brightness;
    } else if (strcmp(func, "image_flip") == 0){
      ret = &wasmimport_image_flip;
    } else if (strcmp(func, "color_contrast") == 0){
      ret = &wasmimport_color_contrast;
    } else if (strcmp(func, "image_color_contrast") == 0){
      ret = &wasmimport_image_color_contrast;
    } else if (strcmp(func, "image_alpha_mask") == 0){
      ret = &wasmimport_image_alpha_mask;
    } else if (strcmp(func, "image_rotate") == 0){
      ret = &wasmimport_image_rotate;
    } else if (strcmp(func, "image_gradient") == 0){
      ret = &wasmimport_image_gradient;
    } else if (strcmp(func, "color_bilinear_interpolate") == 0){
      ret = &wasmimport_color_bilinear_interpolate;
    } else if (strcmp(func, "load_sound") == 0){
      ret = &wasmimport_load_sound;
    } else if (strcmp(func, "play_sound") == 0){
      ret = &wasmimport_play_sound;
    } else if (strcmp(func, "stop_sound") == 0){
      ret = &wasmimport_stop_sound;
    } else if (strcmp(func, "delta_time") == 0){
      ret = &wasmimport_delta_time;
    } else if (strcmp(func, "key_pressed") == 0){
      ret = &wasmimport_key_pressed;
    } else if (strcmp(func, "key_down") == 0){
      ret = &wasmimport_key_down;
    } else if (strcmp(func, "key_released") == 0){
      ret = &wasmimport_key_released;
    } else if (strcmp(func, "key_up") == 0){
      ret = &wasmimport_key_up;
    } else if (strcmp(func, "gamepad_button_pressed") == 0){
      ret = &wasmimport_gamepad_button_pressed;
    } else if (strcmp(func, "gamepad_button_down") == 0){
      ret = &wasmimport_gamepad_button_down;
    } else if (strcmp(func, "gamepad_button_released") == 0){
      ret = &wasmimport_gamepad_button_released;
    } else if (strcmp(func, "gamepad_button_up") == 0){
      ret = &wasmimport_gamepad_button_up;
    } else if (strcmp(func, "mouse_position") == 0){
      ret = &wasmimport_mouse_position;
    } else if (strcmp(func, "mouse_button_pressed") == 0){
      ret = &wasmimport_mouse_button_pressed;
    } else if (strcmp(func, "mouse_button_down") == 0){
      ret = &wasmimport_mouse_button_down;
    } else if (strcmp(func, "mouse_button_released") == 0){
      ret = &wasmimport_mouse_button_released;
    } else if (strcmp(func, "mouse_button_up") == 0){
      ret = &wasmimport_mouse_button_up;
    } else if (strcmp(func, "set_title") == 0){
      ret = &wasmimport_set_title;
    }
  }

  if (ret == NULL) {
    return NULL;
  }

  return web49_env_new(state, ret);
}
