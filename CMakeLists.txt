cmake_minimum_required(VERSION 3.13...3.16 FATAL_ERROR)
project(llvm-c-extras VERSION 1.0.0 LANGUAGES CXX)

find_package(LLVM 10.0 REQUIRED CONFIG)
include_directories(SYSTEM "${LLVM_INCLUDE_DIRS}")

set(CMAKE_CXX_STANDARD 14 CACHE STRING "")

if(NOT LLVM_ENABLE_RTTI)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" -fno-rtti)
endif()

add_subdirectory(src)
