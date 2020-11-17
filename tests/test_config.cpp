#include "config_builder.h"
#include <gtest/gtest.h>

TEST(ConfigBuilder, BuildValidConfig) {
  ConfigBuilder::build("./fixtures/valid_config.ini");
  auto& config = Config::instance();

  ASSERT_EQ(config.get_port(), 9999);
  ASSERT_EQ(config.get_concurrency(), 2);
  ASSERT_STREQ(config.get_bind_addr().data(), "localhost");
}

TEST(ConfigBuilder, InvalidArgument) {
  ASSERT_THROW(ConfigBuilder::build("./fixtures/invalid_config1.ini"), std::invalid_argument);
}

TEST(ConfigBuilder, MissingArgument) {
  ASSERT_THROW(ConfigBuilder::build("./fixtures/invalid_config2.ini"), std::exception);
}
