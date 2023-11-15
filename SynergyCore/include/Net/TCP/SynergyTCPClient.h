#pragma once

#include <SynergyCoreExports.h>
#include <Interfaces/Net/Client.h>

class SYNERGYCORE_API SynergyTCPClient : public Client {
public:
  SynergyTCPClient(asio::io_context& nContext, const std::string& nIPAddress, const int nPort)
    : Client(nContext, nPort),
      Socket(nContext),
      Endpoint(asio::ip::tcp::endpoint(asio::ip::make_address(nIPAddress), Port)) { }

  SynergyTCPClient(asio::io_context& nContext, const std::string& nIPAddress)
    : Client(nContext, SYNERGYCORE_TCP_PORT),
      Socket(nContext),
      Endpoint(asio::ip::tcp::endpoint(asio::ip::make_address(nIPAddress), Port)) { }

  void Start() override;
  void SendMsg(PayloadBase*) override;
  void SendMsgAsync(PayloadBase*) override;

private:
  asio::ip::tcp::socket Socket;
  asio::ip::tcp::endpoint Endpoint;
};