#pragma once

#include <SynergyCoreExports.h>
#include "PayloadBase.h"

class SYNERGYCORE_API HelloPayload : public PayloadBase {
public:
  HelloPayload();

  std::string Serialize() const override;
  void Deserialize(const std::string&) override;

  std::string Message;
};