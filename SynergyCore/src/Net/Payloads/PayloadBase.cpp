#include <Net/Payloads/PayloadBase.h>

void PayloadBase::BaseDeserialize(json* nJson) {
  this->TypeOfPayload = static_cast<PayloadType>((*nJson)[TYPE_OF_PAYLOAD_KEY]);
}

void PayloadBase::BaseSerialize(json* nJson) const {
  (*nJson)[TYPE_OF_PAYLOAD_KEY] = static_cast<int>(TypeOfPayload);
}