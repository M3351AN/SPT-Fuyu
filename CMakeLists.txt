cmake_minimum_required(VERSION 3.16)

project(SPTFuyuHook)

set(CMAKE_CXX_STANDARD 23)

add_library(SPTFuyuHook SHARED spt_fuyu_hook.cc)

target_include_directories(SPTFuyuHook PUBLIC include)

add_library(minhook STATIC
        minhook/buffer.c
        minhook/hook.c
        minhook/trampoline.c
        minhook/hde/hde64.c
)

target_include_directories(minhook PUBLIC include)

target_link_libraries(SPTFuyuHook PRIVATE minhook)
