// this will generate the web49 header for null0

import api from '../api_null0.json' assert { type: 'json' }

function indent(str, numOfIndents=0, opt_spacesPerIndent=2) {
  str = str.replace(/^(?=.)/gm, new Array(numOfIndents + 1).join('\t'));
  numOfIndents = new Array(opt_spacesPerIndent + 1 || 0).join(' '); // re-use
  return opt_spacesPerIndent
    ? str.replace(/^\t+/g, function(tabs) {
        return tabs.replace(/./g, numOfIndents);
    })
    : str;
}

function getArgs(func) {
  let out = []

  if (func.pntr_args['app'] === 'pntr_app*') {
    out.push('pntr_app* app = null0_app;')
  }

  return out.length ? indent((out.join('\n') + '\n  ')) : ''
}


let out = `// Null0 web49 host-bindings generated at ${new Date().toISOString()}

static web49_interp_data_t wasi_import_generic(void* wasi_untyped, web49_interp_t interp) {
  printf("Unkown import called\\n");
}
`

for (const name of Object.keys(api)) {
  const func = api[name]

  let body = getArgs(func)
  body += func.returns === 'void' ? '' : `${func.returns} retVal = `
  body += `${func.pntr_name}(${Object.keys(func.pntr_args).join(', ')});`

  out += `
static web49_interp_data_t null0_wasmimport_${name}(void* wasi_untyped, web49_interp_t interp) {
  ${body}
}
`
}

console.log(out)