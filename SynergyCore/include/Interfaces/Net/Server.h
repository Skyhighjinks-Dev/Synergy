#pragma once

#include <SynergyCoreExports.h>
#include "NetworkBase.h"

class SYNERGYCORE_API Server : public NetworkBase {
public:
  Server(asio::io_context& nContext, const int nPort)
    : NetworkBase(nContext, nPort) { }

  virtual void Start() override = 0;

protected:
  // List of connected clients <IP address>
};