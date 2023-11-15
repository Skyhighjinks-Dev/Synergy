#pragma once

#include <SynergyCoreExports.h>
#include <Net/TCP/SynergyTCPServer.h>
#include <Net/UDP/SynergyUDPServer.h>

class SYNERGYCORE_API SynergyServerManager {
public:
  SynergyServerManager(asio::io_context& nContext, const int nPort)
    : TCPServer(nContext, nPort),
      UDPServer(nContext, nPort) { }

  SynergyServerManager(asio::io_context& nContext)
    : TCPServer(nContext),
      UDPServer(nContext) { }

  SynergyTCPServer TCPServer;
  SynergyUDPServer UDPServer;
};