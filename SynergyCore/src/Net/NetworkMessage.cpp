#include <Net/NetworkMessage.h>
#include <json.hpp>

using namespace nlohmann;

/// <summary>
/// Constructor
/// </summary>
/// <param name="nPayload">Payload pointer</param>
NetworkMessage::NetworkMessage(PayloadBase* nPayload)
  : MessageID(1),
  Payload(nPayload) {}


/// <summary>
/// Serialize network message
/// </summary>
/// <returns>JSON string representing this object</returns>
std::string NetworkMessage::Serialize() const {
  json j;
  j["MessageID"] = MessageID;

  if(Payload != nullptr) {
    j["Payload"] = Payload->Serialize();
  }

  return j.dump();
}


/// <summary>
/// Deserialize object
/// </summary>
/// <param name="nJson">Parses json data into this object</param>
void NetworkMessage::Deserialize(const std::string& nJson) {
  json j = json::parse(nJson);
  
  MessageID = j["MessageID"];

  if(j.find("Payload") != j.end() && Payload != nullptr) {
    Payload->Deserialize(j["Payload"].dump());
  }
}