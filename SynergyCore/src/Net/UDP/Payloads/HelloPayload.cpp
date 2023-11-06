#include <Net/Payloads/HelloPayload.h>

using nlohmann::json;

HelloPayload::HelloPayload() : PayloadBase(PayloadType::HELLO) {

}

std::string HelloPayload::Serialize() const {
  json j;
  j["Type"] = static_cast<int>(Type);
  j["Message"] = Message;
  
  return j.dump();
}

void HelloPayload::Deserialize(const std::string& nJson)
{
  json j = json::parse(nJson);
  this->Type = static_cast<PayloadType>(j["Type"]);
  this->Message = j["Message"];
}