#include <iostream>
#include <Net/TCP/SynergyTCPServer.h>
#include <asio.hpp>

int main()
{
  try {
    asio::io_context context;
    SynergyTCPServer s(context);

    s.Start();
    
    context.run();
  }
  catch(const std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::string msg;
  std::cin >> msg;
}