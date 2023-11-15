#pragma once

#include <SynergyCoreExports.h>
#include <Interfaces/Serializable.h>
#include "PayloadType.h"
#include <json.hpp>

#define TYPE_OF_PAYLOAD_KEY "PayloadType"

using nlohmann::json;

class SYNERGYCORE_API PayloadBase : public Serializable {
public:
  PayloadBase(PayloadType nPayloadType)
    : TypeOfPayload(nPayloadType) { }

  virtual std::string Serialize() const override = 0;;
  virtual void Deserialize(const std::string&) override = 0;
  
  PayloadType TypeOfPayload = PayloadType::NONE;

protected:
  void BaseSerialize(json*) const;
  void BaseDeserialize(json*);

};