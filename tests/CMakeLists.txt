cmake_minimum_required(VERSION 3.10)

project(test_project)

add_executable(ws_server_tests_runner test_config.cpp test_ws_server.cpp)

target_include_directories(
  ws_server_tests_runner PRIVATE
    ${gtest_SOURCE_DIR}/include
    ${gtest_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(
  ws_server_tests_runner PRIVATE
    gtest
    gtest_main
    pthread
    ${CONAN_LIBS}
    ws_server_lib
)

add_test(NAME tests_ws_server COMMAND ws_server_tests_runner)
