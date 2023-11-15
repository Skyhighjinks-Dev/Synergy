#pragma once

#include <SynergyCoreExports.h>
#include <asio.hpp>

class SYNERGYCORE_API NetworkBase {
public:
  NetworkBase(asio::io_context& nContext, const int nPort)
    : Context(nContext),
      Port(nPort) { }

  virtual void Start() = 0;
  
  asio::io_context& GetContext() {
    return Context;
  }

  const int GetPort() {
    return Port;
  }


protected:
  const int Port;
  asio::io_context& Context;
};