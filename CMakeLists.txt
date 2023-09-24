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

find_package(web49 REQUIRED)
find_package(mattiasgustavssonlib REQUIRED)
set(SOURCES src/main.c)

find_package(pntr_app_starter)
