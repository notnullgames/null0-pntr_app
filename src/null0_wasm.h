// Null0 web49 host-bindings generated at 2023-09-25T00:53:50.445Z

static web49_interp_data_t wasi_import_generic(void* wasi_untyped, web49_interp_t interp) {
  printf("Unkown import called\n");
}

static web49_interp_data_t wasmimport_new_image(void* wasi_untyped, web49_interp_t interp) {  
  i32 width = interp.locals[0].i32_s;
  i32 height = interp.locals[1].i32_s;
  u32 color = interp.locals[2].i32_u;
  u32 retVal = pntr_gen_image_color(width, height, color);
}

static web49_interp_data_t wasmimport_image_copy(void* wasi_untyped, web49_interp_t interp) {  
  u32 image = interp.locals[0].i32_u;
  u32 retVal = pntr_image_copy(image);
}

static web49_interp_data_t wasmimport_image_subimage(void* wasi_untyped, web49_interp_t interp) {  
  u32 image = interp.locals[0].i32_u;
  i32 x = interp.locals[1].i32_s;
  i32 y = interp.locals[2].i32_s;
  i32 width = interp.locals[3].i32_s;
  i32 height = interp.locals[4].i32_s;
  u32 retVal = pntr_image_subimage(image, x, y, width, height);
}

static web49_interp_data_t wasmimport_unload_image(void* wasi_untyped, web49_interp_t interp) {  
  u32 image = interp.locals[0].i32_u;
  pntr_unload_image(image);
  
}

static web49_interp_data_t wasmimport_clear_background(void* wasi_untyped, web49_interp_t interp) {  
  u32 image = interp.locals[0].i32_u;
  u32 color = interp.locals[1].i32_u;
  pntr_clear_background(image, color);
  
}

static web49_interp_data_t wasmimport_draw_point(void* wasi_untyped, web49_interp_t interp) {  
  i32 x = interp.locals[0].i32_s;
  i32 y = interp.locals[1].i32_s;
  u32 color = interp.locals[2].i32_u;
  pntr_draw_point(null0->screen, x, y, color);
  
}

static web49_interp_data_t wasmimport_draw_line(void* wasi_untyped, web49_interp_t interp) {  
  i32 startPosX = interp.locals[0].i32_s;
  i32 startPosY = interp.locals[1].i32_s;
  i32 endPosX = interp.locals[2].i32_s;
  i32 endPosY = interp.locals[3].i32_s;
  u32 color = interp.locals[4].i32_u;
  pntr_draw_line(null0->screen, startPosX, startPosY, endPosX, endPosY, color);
  
}

static web49_interp_data_t wasmimport_draw_rectangle_outline(void* wasi_untyped, web49_interp_t interp) {  
  i32 posX = interp.locals[0].i32_s;
  i32 posY = interp.locals[1].i32_s;
  i32 width = interp.locals[2].i32_s;
  i32 height = interp.locals[3].i32_s;
  i32 thickness = interp.locals[4].i32_s;
  u32 color = interp.locals[5].i32_u;
  pntr_draw_rectangle(null0->screen, posX, posY, width, height, thickness, color);
  
}

static web49_interp_data_t wasmimport_draw_rectangle(void* wasi_untyped, web49_interp_t interp) {  
  i32 posX = interp.locals[0].i32_s;
  i32 posY = interp.locals[1].i32_s;
  i32 width = interp.locals[2].i32_s;
  i32 height = interp.locals[3].i32_s;
  u32 color = interp.locals[4].i32_u;
  pntr_draw_rectangle_fill(null0->screen, posX, posY, width, height, color);
  
}

static web49_interp_data_t wasmimport_draw_triangle_outline(void* wasi_untyped, web49_interp_t interp) {  
  i32 x1 = interp.locals[0].i32_s;
  i32 y1 = interp.locals[1].i32_s;
  i32 x2 = interp.locals[2].i32_s;
  i32 y2 = interp.locals[3].i32_s;
  i32 x3 = interp.locals[4].i32_s;
  i32 y3 = interp.locals[5].i32_s;
  u32 color = interp.locals[6].i32_u;
  pntr_draw_triangle(null0->screen, x1, y1, x2, y2, x3, y3, color);
  
}

static web49_interp_data_t wasmimport_draw_triangle(void* wasi_untyped, web49_interp_t interp) {  
  i32 x1 = interp.locals[0].i32_s;
  i32 y1 = interp.locals[1].i32_s;
  i32 x2 = interp.locals[2].i32_s;
  i32 y2 = interp.locals[3].i32_s;
  i32 x3 = interp.locals[4].i32_s;
  i32 y3 = interp.locals[5].i32_s;
  u32 color = interp.locals[6].i32_u;
  pntr_draw_triangle_fill(null0->screen, x1, y1, x2, y2, x3, y3, color);
  
}

static web49_interp_data_t wasmimport_draw_ellipse_outline(void* wasi_untyped, web49_interp_t interp) {  
  i32 centerX = interp.locals[0].i32_s;
  i32 centerY = interp.locals[1].i32_s;
  i32 radiusX = interp.locals[2].i32_s;
  i32 radiusY = interp.locals[3].i32_s;
  u32 color = interp.locals[4].i32_u;
  pntr_draw_ellipse(null0->screen, centerX, centerY, radiusX, radiusY, color);
  
}

static web49_interp_data_t wasmimport_draw_ellipse(void* wasi_untyped, web49_interp_t interp) {  
  i32 centerX = interp.locals[0].i32_s;
  i32 centerY = interp.locals[1].i32_s;
  i32 radiusX = interp.locals[2].i32_s;
  i32 radiusY = interp.locals[3].i32_s;
  u32 color = interp.locals[4].i32_u;
  pntr_draw_ellipse_fill(null0->screen, centerX, centerY, radiusX, radiusY, color);
  
}

static web49_interp_data_t wasmimport_draw_circle_outline(void* wasi_untyped, web49_interp_t interp) {  
  i32 centerX = interp.locals[0].i32_s;
  i32 centerY = interp.locals[1].i32_s;
  i32 radius = interp.locals[2].i32_s;
  u32 color = interp.locals[3].i32_u;
  pntr_draw_circle(null0->screen, centerX, centerY, radius, color);
  
}

static web49_interp_data_t wasmimport_draw_circle(void* wasi_untyped, web49_interp_t interp) {  
  i32 centerX = interp.locals[0].i32_s;
  i32 centerY = interp.locals[1].i32_s;
  i32 radius = interp.locals[2].i32_s;
  u32 color = interp.locals[3].i32_u;
  pntr_draw_circle_fill(null0->screen, centerX, centerY, radius, color);
  
}

static web49_interp_data_t wasmimport_draw_polygon_outline(void* wasi_untyped, web49_interp_t interp) {  
  Vec2* points = (Vec2*) interp.memory[interp.locals[0].i32_u];
  i32 numPoints = interp.locals[1].i32_s;
  u32 color = interp.locals[2].i32_u;
  pntr_draw_polygon(null0->screen, points, numPoints, color);
  
}

static web49_interp_data_t wasmimport_draw_polygon(void* wasi_untyped, web49_interp_t interp) {  
  Vec2* points = (Vec2*) interp.memory[interp.locals[0].i32_u];
  i32 numPoints = interp.locals[1].i32_s;
  u32 color = interp.locals[2].i32_u;
  pntr_draw_polygon_fill(null0->screen, points, numPoints, color);
  
}

static web49_interp_data_t wasmimport_draw_polyline(void* wasi_untyped, web49_interp_t interp) {  
  Vec2* points = (Vec2*) interp.memory[interp.locals[0].i32_u];
  i32 numPoints = interp.locals[1].i32_s;
  u32 color = interp.locals[2].i32_u;
  pntr_draw_polyline(null0->screen, points, numPoints, color);
  
}

static web49_interp_data_t wasmimport_draw_arc_outline(void* wasi_untyped, web49_interp_t interp) {  
  i32 centerX = interp.locals[0].i32_s;
  i32 centerY = interp.locals[1].i32_s;
  f32 radius = interp.locals[2].f32;
  f32 startAngle = interp.locals[3].f32;
  f32 endAngle = interp.locals[4].f32;
  i32 segments = interp.locals[5].i32_s;
  u32 color = interp.locals[6].i32_u;
  pntr_draw_arc(null0->screen, centerX, centerY, radius, startAngle, endAngle, segments, color);
  
}

static web49_interp_data_t wasmimport_draw_arc(void* wasi_untyped, web49_interp_t interp) {  
  i32 centerX = interp.locals[0].i32_s;
  i32 centerY = interp.locals[1].i32_s;
  f32 radius = interp.locals[2].f32;
  f32 startAngle = interp.locals[3].f32;
  f32 endAngle = interp.locals[4].f32;
  i32 segments = interp.locals[5].i32_s;
  u32 color = interp.locals[6].i32_u;
  pntr_draw_arc_fill(null0->screen, centerX, centerY, radius, startAngle, endAngle, segments, color);
  
}

static web49_interp_data_t wasmimport_draw_rectangle_rounded_outline(void* wasi_untyped, web49_interp_t interp) {  
  i32 x = interp.locals[0].i32_s;
  i32 y = interp.locals[1].i32_s;
  i32 width = interp.locals[2].i32_s;
  i32 height = interp.locals[3].i32_s;
  i32 topLeftRadius = interp.locals[4].i32_s;
  i32 topRightRadius = interp.locals[5].i32_s;
  i32 bottomLeftRadius = interp.locals[6].i32_s;
  i32 bottomRightRadius = interp.locals[7].i32_s;
  u32 color = interp.locals[8].i32_u;
  pntr_draw_rectangle_rounded(null0->screen, x, y, width, height, topLeftRadius, topRightRadius, bottomLeftRadius, bottomRightRadius, color);
  
}

static web49_interp_data_t wasmimport_draw_rectangle_rounded(void* wasi_untyped, web49_interp_t interp) {  
  i32 x = interp.locals[0].i32_s;
  i32 y = interp.locals[1].i32_s;
  i32 width = interp.locals[2].i32_s;
  i32 height = interp.locals[3].i32_s;
  i32 cornerRadius = interp.locals[4].i32_s;
  u32 color = interp.locals[5].i32_u;
  pntr_draw_rectangle_rounded_fill(null0->screen, x, y, width, height, cornerRadius, color);
  
}

static web49_interp_data_t wasmimport_draw_image(void* wasi_untyped, web49_interp_t interp) {  
  u32 src = interp.locals[0].i32_u;
  i32 posX = interp.locals[1].i32_s;
  i32 posY = interp.locals[2].i32_s;
  pntr_draw_image(null0->screen, src, posX, posY);
  
}

static web49_interp_data_t wasmimport_draw_image_tint(void* wasi_untyped, web49_interp_t interp) {  
  u32 src = interp.locals[0].i32_u;
  i32 posX = interp.locals[1].i32_s;
  i32 posY = interp.locals[2].i32_s;
  u32 tint = interp.locals[3].i32_u;
  pntr_draw_image_tint(null0->screen, src, posX, posY, tint);
  
}

static web49_interp_data_t wasmimport_draw_image_rotated(void* wasi_untyped, web49_interp_t interp) {  
  u32 src = interp.locals[0].i32_u;
  i32 posX = interp.locals[1].i32_s;
  i32 posY = interp.locals[2].i32_s;
  f32 degrees = interp.locals[3].f32;
  f32 offsetX = interp.locals[4].f32;
  f32 offsetY = interp.locals[5].f32;
  pntr_filter filter = interp.locals[6].i32_u;
  pntr_draw_image_rotated(null0->screen, src, posX, posY, degrees, offsetX, offsetY, filter);
  
}

static web49_interp_data_t wasmimport_draw_image_flipped(void* wasi_untyped, web49_interp_t interp) {  
  u32 src = interp.locals[0].i32_u;
  i32 posX = interp.locals[1].i32_s;
  i32 posY = interp.locals[2].i32_s;
  bool flipHorizontal = interp.locals[3].i32_u;
  bool flipVertical = interp.locals[4].i32_u;
  pntr_draw_image_flipped(null0->screen, src, posX, posY, flipHorizontal, flipVertical);
  
}

static web49_interp_data_t wasmimport_draw_image_scaled(void* wasi_untyped, web49_interp_t interp) {  
  u32 src = interp.locals[0].i32_u;
  i32 posX = interp.locals[1].i32_s;
  i32 posY = interp.locals[2].i32_s;
  f32 scaleX = interp.locals[3].f32;
  f32 scaleY = interp.locals[4].f32;
  f32 offsetX = interp.locals[5].f32;
  f32 offsetY = interp.locals[6].f32;
  pntr_filter filter = interp.locals[7].i32_u;
  pntr_draw_image_scaled(null0->screen, src, posX, posY, scaleX, scaleY, offsetX, offsetY, filter);
  
}

static web49_interp_data_t wasmimport_draw_text(void* wasi_untyped, web49_interp_t interp) {  
  pntr_font* font = null0_fonts[ interp.locals[0].undefined ];
  const char* text = (const char*) interp.memory[interp.locals[1].i32_u];
  i32 posX = interp.locals[2].i32_s;
  i32 posY = interp.locals[3].i32_s;
  u32 color = interp.locals[4].i32_u;
  pntr_draw_text(null0->screen, font, text, posX, posY, color);
  
}

static web49_interp_data_t wasmimport_save_file(void* wasi_untyped, web49_interp_t interp) {  
  const char* fileName = (const char*) interp.memory[interp.locals[0].i32_u];
  const void* data = (const void*) interp.memory[interp.locals[1].i32_u];
  unsigned int bytesToWrite = interp.locals[2].undefined;
  bool retVal = pntr_save_file(fileName, data, bytesToWrite);
}

static web49_interp_data_t wasmimport_save_image(void* wasi_untyped, web49_interp_t interp) {  
  u32 image = interp.locals[0].i32_u;
  const char* fileName = (const char*) interp.memory[interp.locals[1].i32_u];
  bool retVal = pntr_save_image(image, fileName);
}

static web49_interp_data_t wasmimport_load_image(void* wasi_untyped, web49_interp_t interp) {  
  const char* fileName = (const char*) interp.memory[interp.locals[0].i32_u];
  u32 retVal = pntr_load_image(fileName);
}

static web49_interp_data_t wasmimport_image_resize(void* wasi_untyped, web49_interp_t interp) {  
  u32 image = interp.locals[0].i32_u;
  i32 newWidth = interp.locals[1].i32_s;
  i32 newHeight = interp.locals[2].i32_s;
  i32 offsetX = interp.locals[3].i32_s;
  i32 offsetY = interp.locals[4].i32_s;
  u32 fill = interp.locals[5].i32_u;
  bool retVal = pntr_image_resize_canvas(image, newWidth, newHeight, offsetX, offsetY, fill);
}

static web49_interp_data_t wasmimport_image_scale(void* wasi_untyped, web49_interp_t interp) {  
  u32 image = interp.locals[0].i32_u;
  f32 scaleX = interp.locals[1].f32;
  f32 scaleY = interp.locals[2].f32;
  pntr_filter filter = interp.locals[3].i32_u;
  u32 retVal = pntr_image_scale(image, scaleX, scaleY, filter);
}

static web49_interp_data_t wasmimport_image_color_replace(void* wasi_untyped, web49_interp_t interp) {  
  u32 image = interp.locals[0].i32_u;
  u32 color = interp.locals[1].i32_u;
  u32 replace = interp.locals[2].i32_u;
  pntr_image_color_replace(image, color, replace);
  
}

static web49_interp_data_t wasmimport_color_tint(void* wasi_untyped, web49_interp_t interp) {  
  u32 color = interp.locals[0].i32_u;
  u32 tint = interp.locals[1].i32_u;
  u32 retVal = pntr_color_tint(color, tint);
}

static web49_interp_data_t wasmimport_image_color_tint(void* wasi_untyped, web49_interp_t interp) {  
  u32 image = interp.locals[0].i32_u;
  u32 color = interp.locals[1].i32_u;
  pntr_image_color_tint(image, color);
  
}

static web49_interp_data_t wasmimport_color_fade(void* wasi_untyped, web49_interp_t interp) {  
  u32 color = interp.locals[0].i32_u;
  f32 alpha = interp.locals[1].f32;
  u32 retVal = pntr_color_fade(color, alpha);
}

static web49_interp_data_t wasmimport_image_color_fade(void* wasi_untyped, web49_interp_t interp) {  
  u32 image = interp.locals[0].i32_u;
  f32 alpha = interp.locals[1].f32;
  pntr_image_color_fade(image, alpha);
  
}

static web49_interp_data_t wasmimport_color_brightness(void* wasi_untyped, web49_interp_t interp) {  
  u32 color = interp.locals[0].i32_u;
  f32 factor = interp.locals[1].f32;
  u32 retVal = pntr_color_brightness(color, factor);
}

static web49_interp_data_t wasmimport_get_pixel_color(void* wasi_untyped, web49_interp_t interp) {  
  void* srcPtr = (void*) interp.memory[interp.locals[0].i32_u];
  pntr_pixelformat srcPixelFormat = interp.locals[1].undefined;
  u32 retVal = pntr_get_pixel_color(srcPtr, srcPixelFormat);
}

static web49_interp_data_t wasmimport_load_font_default(void* wasi_untyped, web49_interp_t interp) {  
  void = interp.locals[0].undefined;
  pntr_font* retVal = pntr_load_font_default(void);
}

static web49_interp_data_t wasmimport_unload_font(void* wasi_untyped, web49_interp_t interp) {  
  pntr_font* font = null0_fonts[ interp.locals[0].undefined ];
  pntr_unload_font(font);
  
}

static web49_interp_data_t wasmimport_font_copy(void* wasi_untyped, web49_interp_t interp) {  
  pntr_font* font = null0_fonts[ interp.locals[0].undefined ];
  pntr_font* retVal = pntr_font_copy(font);
}

static web49_interp_data_t wasmimport_font_scale(void* wasi_untyped, web49_interp_t interp) {  
  pntr_font* font = null0_fonts[ interp.locals[0].undefined ];
  f32 scaleX = interp.locals[1].f32;
  f32 scaleY = interp.locals[2].f32;
  pntr_filter filter = interp.locals[3].i32_u;
  pntr_font* retVal = pntr_font_scale(font, scaleX, scaleY, filter);
}

static web49_interp_data_t wasmimport_load_font_bmf(void* wasi_untyped, web49_interp_t interp) {  
  const char* fileName = (const char*) interp.memory[interp.locals[0].i32_u];
  const char* characters = (const char*) interp.memory[interp.locals[1].i32_u];
  pntr_font* retVal = pntr_load_font_bmf(fileName, characters);
}

static web49_interp_data_t wasmimport_load_font_bmf_from_image(void* wasi_untyped, web49_interp_t interp) {  
  u32 image = interp.locals[0].i32_u;
  const char* characters = (const char*) interp.memory[interp.locals[1].i32_u];
  pntr_font* retVal = pntr_load_font_bmf_from_image(image, characters);
}

static web49_interp_data_t wasmimport_measure_text(void* wasi_untyped, web49_interp_t interp) {  
  pntr_font* font = null0_fonts[ interp.locals[0].undefined ];
  const char* text = (const char*) interp.memory[interp.locals[1].i32_u];
  i32 retVal = pntr_measure_text(font, text);
}

static web49_interp_data_t wasmimport_gen_image_text(void* wasi_untyped, web49_interp_t interp) {  
  pntr_font* font = null0_fonts[ interp.locals[0].undefined ];
  const char* text = (const char*) interp.memory[interp.locals[1].i32_u];
  u32 tint = interp.locals[2].i32_u;
  u32 retVal = pntr_gen_image_text(font, text, tint);
}

static web49_interp_data_t wasmimport_load_font_tty(void* wasi_untyped, web49_interp_t interp) {  
  const char* fileName = (const char*) interp.memory[interp.locals[0].i32_u];
  i32 glyphWidth = interp.locals[1].i32_s;
  i32 glyphHeight = interp.locals[2].i32_s;
  const char* characters = (const char*) interp.memory[interp.locals[3].i32_u];
  pntr_font* retVal = pntr_load_font_tty(fileName, glyphWidth, glyphHeight, characters);
}

static web49_interp_data_t wasmimport_load_font_tty_from_image(void* wasi_untyped, web49_interp_t interp) {  
  u32 image = interp.locals[0].i32_u;
  i32 glyphWidth = interp.locals[1].i32_s;
  i32 glyphHeight = interp.locals[2].i32_s;
  const char* characters = (const char*) interp.memory[interp.locals[3].i32_u];
  pntr_font* retVal = pntr_load_font_tty_from_image(image, glyphWidth, glyphHeight, characters);
}

static web49_interp_data_t wasmimport_load_file(void* wasi_untyped, web49_interp_t interp) {  
  const char* fileName = (const char*) interp.memory[interp.locals[0].i32_u];
  unsigned int* bytesRead = (unsigned int*) interp.memory[interp.locals[1].i32_u];
  unsigned char* retVal = pntr_load_file(fileName, bytesRead);
}

static web49_interp_data_t wasmimport_unload_file(void* wasi_untyped, web49_interp_t interp) {  
  unsigned char* fileData = (unsigned char*) interp.memory[interp.locals[0].i32_u];
  pntr_unload_file(fileData);
  
}

static web49_interp_data_t wasmimport_load_file_text(void* wasi_untyped, web49_interp_t interp) {  
  const char* fileName = (const char*) interp.memory[interp.locals[0].i32_u];
  const char* retVal = pntr_load_file_text(fileName);
}

static web49_interp_data_t wasmimport_unload_file_text(void* wasi_untyped, web49_interp_t interp) {  
  const char* text = (const char*) interp.memory[interp.locals[0].i32_u];
  pntr_unload_file_text(text);
  
}

static web49_interp_data_t wasmimport_load_font_ttf(void* wasi_untyped, web49_interp_t interp) {  
  const char* fileName = (const char*) interp.memory[interp.locals[0].i32_u];
  i32 fontSize = interp.locals[1].i32_s;
  pntr_font* retVal = pntr_load_font_ttf(fileName, fontSize);
}

static web49_interp_data_t wasmimport_color_invert(void* wasi_untyped, web49_interp_t interp) {  
  u32 color = interp.locals[0].i32_u;
  u32 retVal = pntr_color_invert(color);
}

static web49_interp_data_t wasmimport_image_color_invert(void* wasi_untyped, web49_interp_t interp) {  
  u32 image = interp.locals[0].i32_u;
  pntr_image_color_invert(image);
  
}

static web49_interp_data_t wasmimport_color_alpha_blend(void* wasi_untyped, web49_interp_t interp) {  
  u32 dst = interp.locals[0].i32_u;
  u32 src = interp.locals[1].i32_u;
  u32 retVal = pntr_color_alpha_blend(dst, src);
}

static web49_interp_data_t wasmimport_image_alpha_border(void* wasi_untyped, web49_interp_t interp) {  
  u32 image = interp.locals[0].i32_u;
  f32 threshold = interp.locals[1].f32;
  pntr_rectangle retVal = pntr_image_alpha_border(image, threshold);
}

static web49_interp_data_t wasmimport_image_crop(void* wasi_untyped, web49_interp_t interp) {  
  u32 image = interp.locals[0].i32_u;
  i32 x = interp.locals[1].i32_s;
  i32 y = interp.locals[2].i32_s;
  i32 width = interp.locals[3].i32_s;
  i32 height = interp.locals[4].i32_s;
  bool retVal = pntr_image_crop(image, x, y, width, height);
}

static web49_interp_data_t wasmimport_image_alpha_crop(void* wasi_untyped, web49_interp_t interp) {  
  u32 image = interp.locals[0].i32_u;
  f32 threshold = interp.locals[1].f32;
  pntr_image_alpha_crop(image, threshold);
  
}

static web49_interp_data_t wasmimport_image_color_brightness(void* wasi_untyped, web49_interp_t interp) {  
  u32 image = interp.locals[0].i32_u;
  f32 factor = interp.locals[1].f32;
  pntr_image_color_brightness(image, factor);
  
}

static web49_interp_data_t wasmimport_image_flip(void* wasi_untyped, web49_interp_t interp) {  
  u32 image = interp.locals[0].i32_u;
  bool horizontal = interp.locals[1].i32_u;
  bool vertical = interp.locals[2].i32_u;
  pntr_image_flip(image, horizontal, vertical);
  
}

static web49_interp_data_t wasmimport_color_contrast(void* wasi_untyped, web49_interp_t interp) {  
  u32 color = interp.locals[0].i32_u;
  f32 contrast = interp.locals[1].f32;
  u32 retVal = pntr_color_contrast(color, contrast);
}

static web49_interp_data_t wasmimport_image_color_contrast(void* wasi_untyped, web49_interp_t interp) {  
  u32 image = interp.locals[0].i32_u;
  f32 contrast = interp.locals[1].f32;
  pntr_image_color_contrast(image, contrast);
  
}

static web49_interp_data_t wasmimport_image_alpha_mask(void* wasi_untyped, web49_interp_t interp) {  
  u32 image = interp.locals[0].i32_u;
  u32 alphaMask = interp.locals[1].i32_u;
  i32 posX = interp.locals[2].i32_s;
  i32 posY = interp.locals[3].i32_s;
  pntr_image_alpha_mask(image, alphaMask, posX, posY);
  
}

static web49_interp_data_t wasmimport_image_rotate(void* wasi_untyped, web49_interp_t interp) {  
  u32 image = interp.locals[0].i32_u;
  f32 degrees = interp.locals[1].f32;
  pntr_filter filter = interp.locals[2].i32_u;
  u32 retVal = pntr_image_rotate(image, degrees, filter);
}

static web49_interp_data_t wasmimport_image_gradient(void* wasi_untyped, web49_interp_t interp) {  
  i32 width = interp.locals[0].i32_s;
  i32 height = interp.locals[1].i32_s;
  u32 topLeft = interp.locals[2].i32_u;
  u32 topRight = interp.locals[3].i32_u;
  u32 bottomLeft = interp.locals[4].i32_u;
  u32 bottomRight = interp.locals[5].i32_u;
  u32 retVal = pntr_gen_image_gradient(width, height, topLeft, topRight, bottomLeft, bottomRight);
}

static web49_interp_data_t wasmimport_color_bilinear_interpolate(void* wasi_untyped, web49_interp_t interp) {  
  u32 color00 = interp.locals[0].i32_u;
  u32 color01 = interp.locals[1].i32_u;
  u32 color10 = interp.locals[2].i32_u;
  u32 color11 = interp.locals[3].i32_u;
  f32 coordinateX = interp.locals[4].f32;
  f32 coordinateY = interp.locals[5].f32;
  u32 retVal = pntr_color_bilinear_interpolate(color00, color01, color10, color11, coordinateX, coordinateY);
}

static web49_interp_data_t wasmimport_load_sound(void* wasi_untyped, web49_interp_t interp) {  
  const char* fileName = (const char*) interp.memory[interp.locals[0].i32_u];
  pntr_sound* retVal = pntr_load_sound(fileName);
}

static web49_interp_data_t wasmimport_unload_sound(void* wasi_untyped, web49_interp_t interp) {  
  pntr_sound* sound = null0_sounds[ interp.locals[0].undefined ];
  pntr_unload_sound(sound);
  
}

static web49_interp_data_t wasmimport_play_sound(void* wasi_untyped, web49_interp_t interp) {  
  pntr_sound* sound = null0_sounds[ interp.locals[0].undefined ];
  bool loop = interp.locals[1].i32_u;
  pntr_play_sound(sound, loop);
  
}

static web49_interp_data_t wasmimport_stop_sound(void* wasi_untyped, web49_interp_t interp) {  
  pntr_sound* sound = null0_sounds[ interp.locals[0].undefined ];
  pntr_stop_sound(sound);
  
}

static web49_interp_data_t wasmimport_delta_time(void* wasi_untyped, web49_interp_t interp) {  
  f32 retVal = pntr_app_delta_time(null0->app);
}

static web49_interp_data_t wasmimport_key_pressed(void* wasi_untyped, web49_interp_t interp) {  
  pntr_app_key key = interp.locals[0].undefined;
  bool retVal = pntr_app_key_pressed(null0->app, key);
}

static web49_interp_data_t wasmimport_key_down(void* wasi_untyped, web49_interp_t interp) {  
  pntr_app_key key = interp.locals[0].undefined;
  bool retVal = pntr_app_key_down(null0->app, key);
}

static web49_interp_data_t wasmimport_key_released(void* wasi_untyped, web49_interp_t interp) {  
  pntr_app_key key = interp.locals[0].undefined;
  bool retVal = pntr_app_key_released(null0->app, key);
}

static web49_interp_data_t wasmimport_key_up(void* wasi_untyped, web49_interp_t interp) {  
  pntr_app_key key = interp.locals[0].undefined;
  bool retVal = pntr_app_key_up(null0->app, key);
}

static web49_interp_data_t wasmimport_gamepad_button_pressed(void* wasi_untyped, web49_interp_t interp) {  
  i32 gamepad = interp.locals[0].i32_s;
  pntr_app_gamepad_button key = interp.locals[1].i32_u;
  bool retVal = pntr_app_gamepad_button_pressed(null0->app, gamepad, key);
}

static web49_interp_data_t wasmimport_gamepad_button_down(void* wasi_untyped, web49_interp_t interp) {  
  i32 gamepad = interp.locals[0].i32_s;
  pntr_app_gamepad_button key = interp.locals[1].i32_u;
  bool retVal = pntr_app_gamepad_button_down(null0->app, gamepad, key);
}

static web49_interp_data_t wasmimport_gamepad_button_released(void* wasi_untyped, web49_interp_t interp) {  
  i32 gamepad = interp.locals[0].i32_s;
  pntr_app_gamepad_button key = interp.locals[1].i32_u;
  bool retVal = pntr_app_gamepad_button_released(null0->app, gamepad, key);
}

static web49_interp_data_t wasmimport_gamepad_button_up(void* wasi_untyped, web49_interp_t interp) {  
  i32 gamepad = interp.locals[0].i32_s;
  pntr_app_gamepad_button key = interp.locals[1].i32_u;
  bool retVal = pntr_app_gamepad_button_up(null0->app, gamepad, key);
}

static web49_interp_data_t wasmimport_mouse_x(void* wasi_untyped, web49_interp_t interp) {  
  i32 retVal = pntr_app_mouse_x(null0->app);
}

static web49_interp_data_t wasmimport_mouse_y(void* wasi_untyped, web49_interp_t interp) {  
  i32 retVal = pntr_app_mouse_y(null0->app);
}

static web49_interp_data_t wasmimport_mouse_delta_x(void* wasi_untyped, web49_interp_t interp) {  
  i32 retVal = pntr_app_mouse_delta_x(null0->app);
}

static web49_interp_data_t wasmimport_mouse_delta_y(void* wasi_untyped, web49_interp_t interp) {  
  i32 retVal = pntr_app_mouse_delta_y(null0->app);
}

static web49_interp_data_t wasmimport_mouse_button_pressed(void* wasi_untyped, web49_interp_t interp) {  
  pntr_app_mouse_button button = interp.locals[0].undefined;
  bool retVal = pntr_app_mouse_button_pressed(null0->app, button);
}

static web49_interp_data_t wasmimport_mouse_button_down(void* wasi_untyped, web49_interp_t interp) {  
  pntr_app_mouse_button button = interp.locals[0].undefined;
  bool retVal = pntr_app_mouse_button_down(null0->app, button);
}

static web49_interp_data_t wasmimport_mouse_button_released(void* wasi_untyped, web49_interp_t interp) {  
  pntr_app_mouse_button button = interp.locals[0].undefined;
  bool retVal = pntr_app_mouse_button_released(null0->app, button);
}

static web49_interp_data_t wasmimport_mouse_button_up(void* wasi_untyped, web49_interp_t interp) {  
  pntr_app_mouse_button button = interp.locals[0].undefined;
  bool retVal = pntr_app_mouse_button_up(null0->app, button);
}

static web49_interp_data_t wasmimport_set_title(void* wasi_untyped, web49_interp_t interp) {  
  const char* title = (const char*) interp.memory[interp.locals[0].i32_u];
  pntr_app_set_title(null0->app, title);
  
}


web49_env_func_t web49_api_null0(void* state, const char* mod, const char* func) {
  web49_env_func_t ret = &wasi_import_generic;
  if (!strcmp(mod, "null0")) {
    if (strcmp(func, "new_image") == 0){
      ret = &wasmimport_new_image;
    } else if (strcmp(func, "image_copy") == 0){
      ret = &wasmimport_image_copy;
    } else if (strcmp(func, "image_subimage") == 0){
      ret = &wasmimport_image_subimage;
    } else if (strcmp(func, "unload_image") == 0){
      ret = &wasmimport_unload_image;
    } else if (strcmp(func, "clear_background") == 0){
      ret = &wasmimport_clear_background;
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
    } else if (strcmp(func, "get_pixel_color") == 0){
      ret = &wasmimport_get_pixel_color;
    } else if (strcmp(func, "load_font_default") == 0){
      ret = &wasmimport_load_font_default;
    } else if (strcmp(func, "unload_font") == 0){
      ret = &wasmimport_unload_font;
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
    } else if (strcmp(func, "unload_file") == 0){
      ret = &wasmimport_unload_file;
    } else if (strcmp(func, "load_file_text") == 0){
      ret = &wasmimport_load_file_text;
    } else if (strcmp(func, "unload_file_text") == 0){
      ret = &wasmimport_unload_file_text;
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
    } else if (strcmp(func, "unload_sound") == 0){
      ret = &wasmimport_unload_sound;
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
    } else if (strcmp(func, "mouse_x") == 0){
      ret = &wasmimport_mouse_x;
    } else if (strcmp(func, "mouse_y") == 0){
      ret = &wasmimport_mouse_y;
    } else if (strcmp(func, "mouse_delta_x") == 0){
      ret = &wasmimport_mouse_delta_x;
    } else if (strcmp(func, "mouse_delta_y") == 0){
      ret = &wasmimport_mouse_delta_y;
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
  return web49_env_new(state, ret);
}

web49_env_func_t web49_main_import_func(void* state, const char* mod, const char* func) {
  if (strcmp(mod, "null0") == 0) {
    return web49_api_null0(state, mod, func);
  } else if (strcmp(mod, "wasi_snapshot_preview1") == 0) {
    return web49_api_wasi(state, mod, func);
  }
  fprintf(stderr, "Unhandled import: %s.%s\n", mod, func);
  return NULL;
}
