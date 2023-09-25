cmake_minimum_required(VERSION 3.11)
project(null0
    DESCRIPTION "null0"
    HOMEPAGE_URL "https://github.com/notnullgames/null0"
    VERSION 0.0.1
    LANGUAGES C
)

option(SDL "Build SDL" TRUE)
option(RAYLIB "Build raylib" TRUE)
option(LIBRETRO "Build libretro" TRUE)
option(CLI "Build CLI" TRUE)
option(WEB "Build Web" TRUE)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/.cmake")

find_package(mattiasgustavssonlib REQUIRED)

set(web49_SOURCES src/web49/api/wasi.c src/web49/ast.c src/web49/interp/interp.c src/web49/io.c src/web49/lib.c src/web49/opt/tee.c src/web49/opt/tree.c src/web49/read_bin.c src/web49/read_wat.c src/web49/tables.c src/web49/write_bin.c src/web49/write_wat.c)
set(SOURCES src/main.c ${web49_SOURCES})

find_package(pntr_app_starter)

