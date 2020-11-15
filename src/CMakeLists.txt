cmake_minimum_required(VERSION 3.10)

project(ws_server VERSION 1.0)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(ws_server main.cpp)
target_link_libraries(ws_server ${CONAN_LIBS})
