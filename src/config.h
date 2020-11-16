#pragma once

#include <string>

class ConfigBuilder;

class Config {
  friend class ConfigBuilder;

  Config() {};
  Config(const Config&) = delete;
  Config(const Config&&) = delete;
  Config& operator=(const Config&) = delete;

  unsigned short port;
  std::string bind_addr;
  unsigned int concurrency;
public:
  static Config& instance() {
    static Config config;
    return config;
  }

  unsigned short get_port() { return port; }
  const std::string& get_bind_addr() { return bind_addr; }
  unsigned int get_concurrency() { return concurrency; }
};
