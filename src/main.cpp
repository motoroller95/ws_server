#include "ws_server.h"
#include <exception>
#include <iostream>

int main(int argc, const char **argv) {
  try {
    WsServer::run(argc, argv);
  } catch (std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}
