#include <iostream>

#include "Net/UDP/SynergyUDPServer.h"

int main()
{
  std::cout << "Starting listening" << std::endl;
  try
  {
    asio::io_context context;
    SynergyUDPServer server(context, SYNERGYCORE_PORT);

    server.StartListening();
    context.run();
  }
  catch(const std::exception& e)
  {
    std::cerr << "Expcetion: " << e.what() << std::endl;
  }

  std::string msg;
  std::cin >> msg;
}