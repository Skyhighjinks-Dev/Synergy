#pragma once

#include <asio.hpp>
#include <SynergyCoreExports.h>

/* UDP Server */
class SYNERGYCORE_API SynergyUDPServer {
public:
  SynergyUDPServer(asio::io_context&, int);
  void StartListening();

private:
  asio::ip::udp::socket Socket;
  asio::ip::udp::endpoint RemoteEndpoint;
  std::array<char, 1024> ReceiveBuffer;
  
  void HandleReceive(const std::error_code&, std::size_t);
};