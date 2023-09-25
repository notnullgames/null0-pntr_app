// this will generate web49 bindings for pntr

import { writeFile } from 'fs/promises'
import pntr_api from '../api.json' assert { type: 'json' }
import null0_map from './null0_map.json' assert { type: 'json' }

const null0_param_map={
  'int': 'i32',
  float: 'f32'
}


const null0_api={}

for (const pntr_name of Object.keys(null0_map)) {
  const null0_name = null0_map[pntr_name]
  const func = pntr_api.find(a => a.name === pntr_name)
  const args = {}
  const null0_args = {}
  const null0_returns = null0_param_map[func.returns] || func.returns || 'void'
  
  for (const arg of (func.args || [])) {
    if (arg[0].includes('*')) {
      arg[0] = arg[0].replace('*', '')
      arg[1] = arg[1] + '*'
    }
    args[arg[0]] = arg[1]
    if (arg[1] !== 'pntr_app*' && !(arg[0] === 'dst' && null0_name.startsWith('draw_'))) {
      null0_args[arg[0]] = null0_param_map[arg[1]] || arg[1]
    }
  }

  null0_api[null0_name] = {
    pntr_name,
    pntr_args: args,
    pntr_returns: func.returns || 'void',
    args: null0_args,
    returns: null0_returns
  }
}

await writeFile('api_null0.json', JSON.stringify(null0_api, null, 2))
