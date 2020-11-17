cmake_minimum_required(VERSION 3.10)

project(ws_server VERSION 1.0)

add_executable(ws_server main.cpp)
add_library(ws_server_lib ws_server.cpp config_builder.cpp)
target_link_libraries(ws_server_lib PUBLIC ${CONAN_LIBS})
target_link_libraries(ws_server PRIVATE ws_server_lib)
