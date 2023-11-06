#pragma once

#include <SynergyCoreExports.h>
#include "PayloadBase.h"

/* Simple hello/handshake payload */
class SYNERGYCORE_API HelloPayload : public PayloadBase {
public:
  HelloPayload();

  std::string Serialize() const override;
  void Deserialize(const std::string&) override;

  std::string Message;
};