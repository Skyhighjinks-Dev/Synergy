#include <Net/Payloads/PayloadBase.h>
#include "json.hpp"

void PayloadBase::BaseSerialize(nlohmann::json* nJson) const {
  (*nJson)["Type"] = static_cast<int>(Type);
}

void PayloadBase::BaseDeserialize(nlohmann::json* nJson) {
  this->Type = static_cast<PayloadType>((*nJson)["Type"]);
}