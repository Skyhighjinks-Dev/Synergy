#include <iostream>

#include <chrono>
#include "Net/UDP/SynergyUDPClient.h"
#include "Net/Payloads/HelloPayload.h"

int main()
{
  std::string serverIP;
  std::cout << "Please enter the IP address of server" << std::endl;
  std::cin >> serverIP;

  asio::io_context context;
  SynergyUDPClient c(context, serverIP, 19810);

  while(true)
  {
    std::cout << "Enter message: " << std::endl;
    HelloPayload hp;
    std::cin >> hp.Message;

    context.run();

    c.SendMsg(&hp);
  }
}