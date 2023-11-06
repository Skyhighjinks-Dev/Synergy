#include <Net/Payloads/PayloadBase.h>
#include "json.hpp"

/// <summary>
/// Base serialization for all payloads
/// </summary>
/// <param name="nJson"></param>
void PayloadBase::BaseSerialize(nlohmann::json* nJson) const {
  (*nJson)["Type"] = static_cast<int>(Type);
}


/// <summary>
/// Base deserialization for all payloads
/// </summary>
/// <param name="nJson">JSON string to deserialize</param>
void PayloadBase::BaseDeserialize(nlohmann::json* nJson) {
  this->Type = static_cast<PayloadType>((*nJson)["Type"]);
}