#pragma once

#include <asio.hpp>
#include <map>
#include <SynergyCoreExports.h>
#include <Net/UDP/SynergyConnectedUDPClient.h>

/* UDP Server */
class SYNERGYCORE_API SynergyUDPServer {
public:
  SynergyUDPServer(asio::io_context&, int);
  void StartListening();

private:
  asio::ip::udp::socket Socket;
  asio::ip::udp::endpoint RemoteEndpoint;
  std::array<char, 1024> ReceiveBuffer;
  
  std::map<std::string, SynergyConnectedUDPClient> ConnectedClients; 


  void HandleReceive(const std::error_code&, std::size_t);
};