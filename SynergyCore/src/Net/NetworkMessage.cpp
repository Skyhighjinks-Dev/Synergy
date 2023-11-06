#include <Net/NetworkMessage.h>
#include <json.hpp>

using namespace nlohmann;

NetworkMessage::NetworkMessage(PayloadBase* nPayload)
  : MessageID(1),
  Payload(nPayload)
{

}

std::string NetworkMessage::Serialize() const {
  json j;
  j["MessageID"] = MessageID;

  if(Payload != nullptr) {
    j["Payload"] = Payload->Serialize();
  }

  return j.dump();
}

void NetworkMessage::Deserialize(const std::string& nJson) {
  json j = json::parse(nJson);
  
  MessageID = j["MessageID"];

  if(j.find("Payload") != j.end() && Payload != nullptr) {
    Payload->Deserialize(j["Payload"].dump());
  }
}