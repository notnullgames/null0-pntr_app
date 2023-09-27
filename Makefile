PWD = ${shell pwd}
DIR_WEB = ${PWD}/docs/carts
DIR_OUT = ${PWD}/build
DIR_CART = ${PWD}/cart

WASI_SYSROOT ?= "${PWD}/wasi-sysroot"

CC_WASM = clang --target=wasm32-wasi --sysroot=${WASI_SYSROOT} -Oz

.PHONY: help
help: ## Show this help
	@grep -E '^[a-zA-Z0-9/._-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "make \033[36m%-30s\033[0m %s\n", $$1, $$2}'


${DIR_OUT}/%.wasm: ${DIR_CART}/%/main.c
	@mkdir -p $(@D)
	${CC_WASM} -Icart/ -o $@ $?

${DIR_WEB}/justlog.null0: ${DIR_OUT}/justlog.wasm
	@cd ${DIR_OUT} && cp $? main.wasm && zip -r $@ main.wasm && rm main.wasm

${DIR_WEB}/hello.null0: ${DIR_OUT}/hello.wasm
	@cd ${DIR_OUT} && cp $? main.wasm && zip -r $@ main.wasm && rm main.wasm

${DIR_WEB}/files.null0: ${DIR_OUT}/files.wasm
	@cd ${DIR_OUT} && cp $? main.wasm && zip -r $@ main.wasm && rm main.wasm
	@cd ${DIR_CART}/files && zip -r $@ . -x "*.c" -x "*.h" -x "*/.DS_Store"

${DIR_WEB}/sound.null0: ${DIR_OUT}/sound.wasm
	@cd ${BUILD_DIR} && cp $? main.wasm && zip -r $@ main.wasm && rm main.wasm
	@cd ${DIR_CART}/sound && zip -r $@ . -x "*.c" -x "*.h" -x "*/.DS_Store"

${DIR_WEB}/tester.null0: ${DIR_OUT}/tester.wasm
	@cd ${BUILD_DIR} && cp $? main.wasm && zip -r $@ main.wasm && rm main.wasm
	@cd ${DIR_CART}/tester && zip -r $@ . -x "*.c" -x "*.h" -x "*/.DS_Store"

.PHONY: web
web: ## Run development web-server
	npx -y live-server docs

.PHONY: all
all: carts runtime ## Build all the things

.PHONY: runtime
runtime: ## Build all native runtime hosts at once
	cmake -B build -DSDL=true -DRAYLIB=true -DLIBRETRO=false -DCLI=true && cmake --build build

.PHONY: runtime_raylib
runtime_raylib: ## Build raylib host
	cmake -B build -DSDL=false -DRAYLIB=true -DLIBRETRO=false -DCLI=false && cmake --build build

.PHONY: runtime_sdl
runtime_sdl: ## Build SDL2 host
	cmake -B build -DSDL=true -DRAYLIB=false -DLIBRETRO=false -DCLI=false && cmake --build build

.PHONY: runtime_libretro
runtime_libretro: ## Build libretro host
	cmake -B build -DSDL=false -DRAYLIB=false -DLIBRETRO=true -DCLI=false && cmake --build build

.PHONY: runtime_cli
runtime_cli: ## build CLI host
	cmake -B build -DSDL=false -DRAYLIB=false -DLIBRETRO=false -DCLI=true && cmake --build build

.PHONY: carts
carts: cart_tester cart_justlog cart_files cart_sound cart_hello ## Build all carts

.PHONY: cart_tester
cart_tester: ${DIR_WEB}/tester.null0	## Build a cart that calls all API functions

.PHONY: cart_justlog
cart_justlog: ${DIR_WEB}/justlog.null0	## Build a minimal demo cart

.PHONY: cart_hello
cart_hello: ${DIR_WEB}/hello.null0	## Build a minimal text-draw demo cart

.PHONY: cart_files
cart_files: ${DIR_WEB}/files.null0	## Build a cart to demo files

.PHONY: cart_sound
cart_sound: ${DIR_WEB}/sound.null0	## Build a cart to demo sound

.PHONY: clean
clean: clean_carts clean_runtime		## Remove all built files

.PHONY: clean_carts
clean_carts: ## Remove carts built files
	@rm -f ${DIR_WEB}/*.null0 ${DIR_OUT}/*.wasm

.PHONY: clean_runtime
clean_runtime: ## Remove runtime built files
	@rm -rf ${DIR_OUT}

.PHONY: gen_cart_c
gen_cart_c: ## DEV: Generate the cart-header for C
	@node ./tools/gen_cart_c_header.mjs

.PHONY: gen_web49
gen_web49:	## DEV: Generate API stub for native host
	@node ./tools/gen_null0_web49.mjs

