#pragma once

#include <SynergyCoreExports.h>
#include <asio.hpp>


class SYNERGYCORE_API SynergyConnectedUDPClient {
public:
  SynergyConnectedUDPClient(const asio::ip::udp::endpoint& nEndpoint)
    : RemoteEndpoint(nEndpoint)
  {
  
  }


  const asio::ip::udp::endpoint& RemoteEndpoint;
};