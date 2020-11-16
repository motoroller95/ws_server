#include "ws_server.h"
#include "config.h"
#include "config_builder.h"
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ip/host_name.hpp>
#include <iostream>

using namespace boost::asio;
using namespace boost::asio::ip;

io_service ioservice;
tcp::resolver resolv{ioservice};

std::string_view get_config_name(int, const char**);

void WsServer::run(int argc, const char **argv) {
  if (!ConfigBuilder::build(get_config_name(argc, argv)))
    return;

  auto& config = Config::instance();
  std::cout << "Concurrency: " << config.get_concurrency() << ", port: " << config.get_port() << std::endl;

  auto& bind_addr = config.get_bind_addr();
  tcp::resolver::query query{bind_addr, ""};
  tcp::resolver::iterator it = resolv.resolve(query);
  while(it != tcp::resolver::iterator()) {
    std::cout << bind_addr << " : " << (it++)->endpoint().address() << std::endl;
  }
}

std::string_view get_config_name(int argc, const char **argv) {
  if (argc == 2)
    return argv[1];

  std::stringstream error_msg;
  error_msg << "Usage: " << argv[0] << " <config file name>";

  throw std::invalid_argument(error_msg.str());
}
