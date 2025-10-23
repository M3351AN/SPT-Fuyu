cmake_minimum_required(VERSION 3.16)
project(SPTFuyuPatcher)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static -static-libgcc 
-static-libstdc++")

add_executable(SPT.Fuyu.Patcher spt_fuyu_patcher.cc app.rc)
