#pragma once

#include <SynergyCoreExports.h>
#include <Net/Payloads/PayloadBase.h>

#include <iostream>
#include <asio.hpp>

class SYNERGYCORE_API SynergyUDPClient {
public:
  SynergyUDPClient(asio::io_context&, const std::string&, int);
  void SendMsg(PayloadBase*);

private:
  asio::ip::udp::socket Socket;
  asio::ip::udp::endpoint ServerEndpoint;
};