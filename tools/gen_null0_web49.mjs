// this will generate the web49 header for null0

import { readFile, writeFile } from 'fs/promises'
import YAML from 'yaml'

const api = YAML.parse(await readFile('tools/api.yml', 'utf8'))

const indent = (str, numOfIndents = 1) => str.split('\n').map(l => ' '.repeat(numOfIndents * 2) + l.trim()).join('\n') + '\n'

const web49Map = {
  u8: 'i32_u',
  bool: 'i32_u',
  u32: 'i32_u',
  i32: 'i32_s',
  u16: 'i32_u',
  i16: 'i32_s',
  u64: 'i64_u',
  i64: 'i64_s',
  f32: 'f32',
  f64: 'f64',
  void: 'void',
  pntr_filter: 'i32_u',
  pntr_app_gamepad_button: 'i32_u',
  'pntr_image*': 'i32_u',
  'unsigned int': 'i32_u',
  pntr_color: 'i32_u',
  pntr_app_key: 'i32_u',
  pntr_app_mouse_button: 'i32_u'

}

let out = `// Null0 web49 host-bindings generated at ${new Date().toISOString()}

// TODO: add vargs
void null0_trace(const char* str) {
  printf("%s\\n", str);
}

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
`

function get_web49_body_return (func) {
  const callArgs = Object.keys(func.host_args || {})

  if (func.returns === 'pntr_image*') {
    return `  return (web49_interp_data_t){.i32_u = null0_add_image(${func.host_name}(${callArgs.join(', ')}))};`
  }
  if (func.returns === 'pntr_font*') {
    return `  return (web49_interp_data_t){.i32_u = null0_add_font(${func.host_name}(${callArgs.join(', ')}))};`
  }
  if (func.returns === 'pntr_sound*') {
    return `  return (web49_interp_data_t){.i32_u = null0_add_sound(${func.host_name}(${callArgs.join(', ')}))};`
  }
  if (func.returns === 'pntr_color') {
    return `  return (web49_interp_data_t){.i32_u = ${func.host_name}(${callArgs.join(', ')}).data };`
  }
  if (func.returns === 'void') {
    return `
  ${func.host_name}(${callArgs.join(', ')});
  return (web49_interp_data_t){.i32_u = 0};
  `
  }

  // TODO: deal with these types
  if (['unsigned char*', 'const char*', 'pntr_rectangle', 'pntr_rectangle*', 'pntr_vector*'].includes(func.returns)) {
    return `// TODO: return ${func.returns}
    ${func.host_name}(${callArgs.join(', ')});
    return (web49_interp_data_t){.i32_u = 0};`
  }

  return `
  return (web49_interp_data_t){.${web49Map[func.returns] || 'i32_u'} = ${func.host_name}(${callArgs.join(', ')})};`
}

function get_web49_wasm_args (func) {
  const params = func.args

  const out = []

  if (func.name.startsWith('draw') && func.host_args.dst) {
    out.push('pntr_image* dst = null0->screen;')
  }

  if (func.host_args.app === 'pntr_app*') {
    out.push('pntr_app* app = null0->app;')
  }

  if (Object.keys(params).length === 0) {
    return indent(out.join('\n'))
  }

  Object.keys(params).forEach((p, i) => {
    if (params[p] === 'pntr_sound*') {
      out.push(`pntr_sound* ${p} = null0->sounds[ interp.locals[${i}].i32_u ];`)
    } else if (params[p] === 'pntr_image*') {
      out.push(`pntr_image* ${p} = null0->images[ interp.locals[${i}].i32_u ];`)
    } else if (params[p] === 'pntr_font*') {
      out.push(`pntr_font* ${p} = null0->fonts[ interp.locals[${i}].i32_u ];`)
    } else if (params[p] === 'pntr_color') {
      out.push(`pntr_color ${p} = pntr_get_color(interp.locals[${i}].i32_u);`)
    } else if (params[p] === 'const char*') {
      out.push(`char* ${p} = WEB49_INTERP_ADDR(char*, interp, interp.locals[${i}].i32_u, 0);`)
    } else if (params[p].includes('*')) {
      out.push(`${params[p]} ${p} = (${params[p]}) interp.memory[interp.locals[${i}].i32_u];`)
    } else {
      out.push(`${params[p]} ${p} = interp.locals[${i}].${web49Map[params[p]]};`)
    }
  })

  return '\n' + indent(out.join('\n  '))
}

const tests = []

for (const name of Object.keys(api)) {
  const func = { name, ...api[name] }
  const args = Object.keys(func.host_args || {})
  tests.push(`(strcmp(func, "${name}") == 0){\n      ret = &wasmimport_${name};\n    }`)
  out += `
static web49_interp_data_t wasmimport_${name}(void* wasi_untyped, web49_interp_t interp) {
  ${args.length ? `${get_web49_wasm_args(func)}\n` : ''}${get_web49_body_return(func)}
}
`
}

out += `
web49_env_func_t web49_api_null0(void* state, const char* mod, const char* func) {
  web49_env_func_t ret = NULL;

  if (!strcmp(mod, "null0")) {
    if ${tests.join(' else if ')}
  }

  if (ret == NULL) {
    return NULL;
  }

  return web49_env_new(state, ret);
}
`

await writeFile('src/null0_wasm.h', out)
