#pragma once

#include <SynergyCoreExports.h>
#include <Interfaces/Serializable.h>
#include <Net/Payloads/PayloadBase.h>

#include <iostream>

/* Network message root object */
class SYNERGYCORE_API NetworkMessage : public Serializable
{
public:
  NetworkMessage(PayloadBase*);

  std::string Serialize() const override;
  void Deserialize(const std::string&) override;

  int MessageID = 1;
  PayloadBase* Payload = nullptr;
};