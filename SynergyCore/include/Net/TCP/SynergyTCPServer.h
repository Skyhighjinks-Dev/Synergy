#pragma once

#include <SynergyCoreExports.h>
#include <Interfaces/Net/Server.h>

class SYNERGYCORE_API SynergyTCPClient : public Server {
public:
  SynergyTCPClient(asio::io_context& nContext, const int nPort)
    : Server(nContext, nPort),
      Socket(Context),
      Acceptor(Context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), Port)) { }

  SynergyTCPClient(asio::io_context& nContext)
    : Server(nContext, SYNERGYCORE_TCP_PORT),
      Socket(Context),
      Acceptor(Context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), Port)) { }
   
  void Start() override;

private:
  void StartAcceptingTCPMessages();

  asio::ip::tcp::acceptor Acceptor;
  asio::ip::tcp::socket Socket;
};