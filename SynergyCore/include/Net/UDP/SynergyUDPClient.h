#pragma once

#include <SynergyCoreExports.h>
#include <Interfaces/Net/Client.h>

class SYNERGYCORE_API SynergyUDPClient : public Client {
public:
  SynergyUDPClient(asio::io_context& nContext, const std::string& nIPAddress, const int nPort)
    : Client(nContext, nPort),
      Socket(Context),
      Endpoint(asio::ip::make_address(nIPAddress), Port) { }

  SynergyUDPClient(asio::io_context& nContext, const std::string& nIPAddress)
    : Client(nContext, SYNERGYCORE_UDP_PORT),
    Socket(Context),
    Endpoint(asio::ip::make_address(nIPAddress), Port) { }

  void Start() override;
  void SendMsg() override;

private:
  asio::ip::udp::socket Socket;
  asio::ip::udp::endpoint Endpoint;
};