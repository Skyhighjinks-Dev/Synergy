#pragma once

#include <SynergyCoreExports.h>
#include "PayloadBase.h"

#define JSON_MESSAGE_KEY "Message"

class SYNERGYCORE_API ConnectPayload : public PayloadBase {
public:
  ConnectPayload() 
    : PayloadBase(PayloadType::HELLO){}

  std::string Serialize() const override;
  void Deserialize(const std::string&) override;

  std::string Message;
  const std::string k_ExpectedMessage = "HELLO SERVER"; // Temporarily used for verification request is legit
};