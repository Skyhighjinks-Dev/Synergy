#include <iostream>
#include <Net/TCP/SynergyTCPClient.h>
#include <Net/Payloads/ConnectPayload.h>
#include <asio.hpp>

/* Currently used for testing - proper implementation will be added once SynergyCore has been developed to a reasonable standard */
int main(int argc, char* argv[])
{
  try
  {
    asio::io_context context;

    SynergyTCPClient c(context, "127.0.0.1");

    c.Start();
    context.poll();

    while (true) {
      std::string placeholder;
      std::cin >> placeholder;

      ConnectPayload p;
      p.Message = p.k_ExpectedMessage;

      c.SendMsgAsync(&p);
    }
  } catch(const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}