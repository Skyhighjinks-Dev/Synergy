#include <Net/Payloads/HelloPayload.h>

using nlohmann::json;

HelloPayload::HelloPayload() : PayloadBase(PayloadType::HELLO) {

}

std::string HelloPayload::Serialize() const {
  json j;
  BaseSerialize(&j);

  j["Message"] = Message;
  
  return j.dump();
}

void HelloPayload::Deserialize(const std::string& nJson)
{
  json j = json::parse(nJson);
  BaseDeserialize(&j);
  this->Message = j["Message"];
}