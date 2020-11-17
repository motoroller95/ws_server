cmake_minimum_required(VERSION 3.10)

project(ws_server VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

enable_testing()

add_subdirectory(googletest)
add_subdirectory(src)
add_subdirectory(tests)
