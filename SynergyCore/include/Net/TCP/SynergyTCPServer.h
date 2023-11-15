#pragma once

#include <SynergyCoreExports.h>
#include <Interfaces/Net/Server.h>
#include <Net/Payloads/PayloadBase.h>

class SYNERGYCORE_API SynergyTCPServer : public Server {
public:
  SynergyTCPServer(asio::io_context& nContext, const int nPort)
    : Server(nContext, nPort),
      Socket(Context),
      Acceptor(Context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), Port)) 
    { 
      Acceptor.listen();
    }

  SynergyTCPServer(asio::io_context& nContext)
    : Server(nContext, SYNERGYCORE_TCP_PORT),
      Socket(Context),
      Acceptor(Context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), Port)) 
    { 
      Acceptor.listen();
    }
   
  void Start() override;

private:
  void StartAcceptingTCPMessagesAsync();
  void StartReadingAsync();

  asio::ip::tcp::acceptor Acceptor;
  asio::ip::tcp::socket Socket;
  std::vector<char> ReceiveBuffer;
};