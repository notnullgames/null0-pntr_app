// this will generate the web49 header for null0

import { writeFile } from 'fs/promises'
import api from '../api_null0.json' assert { type: 'json' }

const indent = (str, numOfIndents=1) => str.split('\n').map(l => ' '.repeat(numOfIndents*2) + l.trim()).join('\n') + '\n'

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
  'pntr_image*': 'i32_u'
}

function get_wasm_args(func) {
  const params = func.args
  if (Object.keys(params).length == 0) {
    return ''
  }
  return '\n  ' + Object.keys(params).map((p, i) => {
    if (params[p] === 'pntr_sound*') {
      return `${params[p]} ${p} = null0->sounds[ interp.locals[${i}].i32_u ];`
    }
    if (params[p] === 'pntr_image*') {
      return `${params[p]} ${p} = null0->images[ interp.locals[${i}].i32_u ];`
    }
    if (params[p] === 'pntr_font*') {
      return `${params[p]} ${p} = null0->fonts[ interp.locals[${i}].i32_u ];`
    }
    if (params[p] === 'pntr_color') {
      return `${params[p]} ${p} = pntr_get_color(interp.locals[${i}].i32_u);`
    }
    if (params[p].includes('*')) {
      return `${params[p]} ${p} = (${params[p]}) interp.memory[interp.locals[${i}].i32_u];`
    }
    return `${params[p]} ${p} = interp.locals[${i}].${web49Map[params[p]]};`
  }).join('\n  ')
}

function get_wasm_call(func) {
  const args = Object.keys(func.pntr_args)
  if (args[0] === 'app') {
    args[0] = 'null0->app'
  }
  if (args[0] === 'dst' && func.name.startsWith('draw_')) {
    args[0] = 'null0->screen'
  }
  if (func.returns === 'void') {
    return `${func.pntr_name}(${args.join(', ')});\nreturn (web49_interp_data_t){.i32_u = 0};`
  }

  return `${func.returns} retVal = ${func.pntr_name}(${args.join(', ')});\nreturn (web49_interp_data_t){.${web49Map[func.returns]} = 0};`
}


let out = `// Null0 web49 host-bindings generated at ${new Date().toISOString()}

static web49_interp_data_t wasi_import_generic(void* wasi_untyped, web49_interp_t interp) {
  printf("Unkown import called\\n");
  return (web49_interp_data_t){.i32_u = 0};
}

`

const tests = []

for (const name of Object.keys(api)) {
  const func = {name, ...api[name]}
  out += `static web49_interp_data_t wasmimport_${name}(void* wasi_untyped, web49_interp_t interp) {`
  out += indent(get_wasm_args(func))
  out += indent(get_wasm_call(func))
  out += '}\n\n'
  tests.push(`(strcmp(func, "${name}") == 0){\n      ret = &wasmimport_${name};\n    }`)
}

out += `
web49_env_func_t web49_api_null0(void* state, const char* mod, const char* func) {
  web49_env_func_t ret = &wasi_import_generic;
  if (!strcmp(mod, "null0")) {
    if ${tests.join(' else if ')}
  }
  return web49_env_new(state, ret);
}
`

await writeFile('src/null0_wasm.h', out)
