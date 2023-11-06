#include <iostream>

#include "Net/UDP/SynergyUDPClient.h"
#include "Net/Payloads/HelloPayload.h"

/* Currently used for testing - proper implementation will be added once SynergyCore has been developed to a reasonable standard */
int main(int argc, char* argv[])
{
  std::string serverIP;

  if(argc < 2)
  {
    std::cout << "Please enter the IP address of server" << std::endl;
    std::cin >> serverIP;
  }
  else
  {
    serverIP = argv[1];
  }

  asio::io_context context;
  SynergyUDPClient c(context, serverIP, SYNERGYCORE_PORT);

  while(true)
  {
    std::cout << "Enter message: " << std::endl;
    HelloPayload hp;
    std::cin >> hp.Message;

    context.run();

    c.SendMsg(&hp);
  }
}