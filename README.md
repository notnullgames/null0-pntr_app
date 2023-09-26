# null0

This is several runtime hosts for null0 game-engine:

- SDL - uses SDL2 for graphics/sound/input
- raylib - uses raylib for graphics/sound/input
- libretro - run your wasm games in retroarch
- cli - uses console graphics!
- web - uses light JS on web

It also includes some demo-carts written in C (more languages, to come.)

```
make help                            # Show this help
make web                             # Run development web-server
make all                             # Build all the things

make runtime_raylib                  # Build raylib host
make runtime_sdl                     # Build SDL2 host
make runtime_libretro                # Build libretro host
make runtime_cli                     # build CLI host

make carts                           # Build all carts
make cart_tester                     # Build a cart that calls all API functions
make cart_justlog                    # Build a minimal demo cart
make cart_hello                      # Build a minimal text-draw demo cart
make cart_files                      # Build a cart to demo files
make cart_sound                      # Build a cart to demo sound

make clean                           # Remove all built files
make clean_carts                     # Remove carts built files
make clean_runtime                   # Remove runtime built files

# BE CAREFUL WITH THESE

make gen_cart_c                      # DEV: Generate the cart-header for C
make gen_web49                       # DEV: Generate API stub for native host
```