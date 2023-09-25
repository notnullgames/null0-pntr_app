// this will generate the web49 header for null0

import { readFile, writeFile } from 'fs/promises'
import YAML from 'yaml'

const api = YAML.parse(await readFile('tools/api.yml', 'utf8'))

const indent = (str, numOfIndents = 1) => str.split('\n').map(l => ' '.repeat(numOfIndents * 2) + l.trim()).join('\n') + '\n'

let out = `// Null0 web49 host-bindings generated at ${new Date().toISOString()}

void null0_clear_screen(pntr_color color) {
    pntr_clear_background(null0->screen, color);
}

`

function get_web49_return (func) {
  return 'return (web49_interp_data_t){.i32_u = 0};'
}

const tests = []

for (const name of Object.keys(api)) {
  const func = { name, ...api[name] }
  tests.push(`(strcmp(func, "${name}") == 0){\n      ret = &wasmimport_${name};\n    }`)
  out += `
static web49_interp_data_t wasmimport_${name}(void* wasi_untyped, web49_interp_t interp) {
  ${get_web49_return(func)}
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
