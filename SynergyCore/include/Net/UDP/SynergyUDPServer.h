#pragma once

#include <SynergyCoreExports.h>
#include <Interfaces/Net/Server.h>

class SYNERGYCORE_API SynergyUDPServer : public Server {
public: 
  SynergyUDPServer(asio::io_context& nContext, const int nPort)
    : Server(nContext, nPort),
      Socket(nContext, asio::ip::udp::endpoint(asio::ip::udp::v4(), Port)) { }

  SynergyUDPServer(asio::io_context& nContext)
    : Server(nContext, SYNERGYCORE_UDP_PORT),
      Socket(nContext, asio::ip::udp::endpoint(asio::ip::udp::v4(), Port)) { }

  void Start() override;

private:
  void StartListening();
  void HandleReceived(const std::error_code&, std::size_t);

  asio::ip::udp::socket Socket;
  asio::ip::udp::endpoint RemoteEndpoint;
};