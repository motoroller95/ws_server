#include "config_builder.h"
#include <iostream>
#include <string>
#include <fstream>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

bool ConfigBuilder::build(std::string_view config_file_name) {
  po::options_description desc("Allowed options");
  desc.add_options()
    ("help", "Produce help message")
    ("bind", po::value<std::string>()->required(), "Address for listening")
    ("port", po::value<unsigned short>()->required(), "Accept connections on the specified port")
    ("concurrency", po::value<unsigned int>()->required(), "Worker threads count");

  po::variables_map vm;
  std::ifstream config_file(config_file_name.data(), std::ifstream::in);
  if (!config_file)
    throw std::runtime_error("Config file not found");

  po::store(po::parse_config_file(config_file, desc), vm);
  po::notify(vm);
  config_file.close();

  auto& config = Config::instance();

  if (vm.count("help")) {
    std::cout << desc << std::endl;
    return false;
  }

  if (vm.count("port"))
    config.port = vm["port"].as<unsigned short>();

  if (vm.count("bind"))
    config.bind_addr = vm["bind"].as<std::string>();

  if (vm.count("concurrency")) {
    config.concurrency = vm["concurrency"].as<unsigned int>();
    if (config.concurrency == 0)
      throw std::invalid_argument("concurrency: invalid value");
  }

  return true;
}
