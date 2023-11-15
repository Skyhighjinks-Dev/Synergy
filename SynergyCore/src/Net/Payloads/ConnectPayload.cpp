#include <Net/Payloads/ConnectPayload.h>

std::string ConnectPayload::Serialize() const {
  json j;
  BaseSerialize(&j);

  j[JSON_MESSAGE_KEY] = Message;
  return j.dump();
}

void ConnectPayload::Deserialize(const std::string& nJson) {
  json j = json::parse(nJson);
  BaseDeserialize(&j);
  this->Message = j[JSON_MESSAGE_KEY];
}