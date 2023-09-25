// Null0 web49 host-bindings generated at 2023-09-25T05:08:07.505Z

static web49_interp_data_t wasi_import_generic(void* wasi_untyped, web49_interp_t interp) {
  printf("Unkown import called\n");
  return (web49_interp_data_t){.i32_u = 0};
}

static web49_interp_data_t wasmimport_color_tint(void* wasi_untyped, web49_interp_t interp) {
  u32 color = interp.locals[0].i32_u;
  u32 tint = interp.locals[1].i32_u;
  pntr_color retVal = pntr_color_tint((pntr_color)color, (pntr_color)tint);
  return (web49_interp_data_t){.i32_u = retVal.data};
}

web49_env_func_t web49_api_null0(void* state, const char* mod, const char* func) {
  web49_env_func_t ret = &wasi_import_generic;
  if (!strcmp(mod, "null0")) {
    if (strcmp(func, "color_tint") == 0) {
      ret = &wasmimport_color_tint;
    }
  }
  return web49_env_new(state, ret);
}
