#pragma once
#include "config.h"
#include <string_view>

class ConfigBuilder {
public:
  static bool build(std::string_view);
};
