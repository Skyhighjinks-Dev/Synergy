#pragma once

#include <SynergyCoreExports.h>
#include <Net/TCP/SynergyTCPClient.h>
#include <Net/UDP/SynergyUDPClient.h>

class SYNERGYCORE_API SynergyClientManager {
public:
  SynergyClientManager(asio::io_context& nContext, const std::string& nIPAddress, const int nTCPPort, const int nUDPPort)
    : TCPClient(nContext, nIPAddress, nTCPPort),
      UDPClient(nContext, nIPAddress, nUDPPort) { }

  SynergyClientManager(asio::io_context& nContext, const std::string& nIPAddress)
    : TCPClient(nContext, nIPAddress),
      UDPClient(nContext, nIPAddress) { }

  void ConnectClients();
  void ConnectTCPClient();
  void ConnectUDPClient();

  void DisconnectClients();
  void DisconnectTCPClient();
  void DisconnectUDPClient();

  void RefreshConnections();
  void RefreshTCPConnection();
  void RefreshUDPConnection();

  SynergyTCPClient TCPClient;
  SynergyUDPClient UDPClient;
};