include(FetchContent)

FETCHCONTENT_DECLARE(mattiasgustavssonlib GIT_REPOSITORY https://github.com/mattiasgustavsson/libs.git GIT_TAG main)
FETCHCONTENT_MAKEAVAILABLE(mattiasgustavssonlib)
INCLUDE_DIRECTORIES(PUBLIC ${mattiasgustavssonlib_SOURCE_DIR})