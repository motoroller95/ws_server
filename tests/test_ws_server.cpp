#include "ws_server.h"
#include <gtest/gtest.h>

TEST(WsServer, ValidArguments) {
  int argc = 2;
  const char *args[2] = { "./tests_runner", "fixtures/valid_config.ini" };

  ASSERT_NO_THROW(WsServer::run(argc, static_cast<const char**>(args)));
}

TEST(WsServer, InvalidArguments) {
  int argc = 1;
  const char *args[1] = { "./tests_runner" };

  ASSERT_THROW(WsServer::run(argc, static_cast<const char**>(args)), std::invalid_argument);
}
