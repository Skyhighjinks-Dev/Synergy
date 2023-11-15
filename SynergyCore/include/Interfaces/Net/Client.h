#pragma once

#include <SynergyCoreExports.h>
#include "NetworkBase.h"

class SYNERGYCORE_API Client : public NetworkBase {
public:
  Client(asio::io_context& nContext, const int nPort)
    : NetworkBase(nContext, nPort) { }
  
  virtual void Start() override = 0;
  virtual void SendMsg() = 0; // Add payload
};