#include <Net/Payloads/HelloPayload.h>

using nlohmann::json;

/// <summary>
/// Constructor
/// </summary>
HelloPayload::HelloPayload() : PayloadBase(PayloadType::HELLO) {

}


/// <summary>
/// Serialize object
/// </summary>
/// <returns>Json serialized object</returns>
std::string HelloPayload::Serialize() const {
  json j;
  BaseSerialize(&j);

  j["Message"] = Message;
  
  return j.dump();
}


/// <summary>
/// Deserializes json string 
/// </summary>
/// <param name="nJson">JSON to deserialize</param>
void HelloPayload::Deserialize(const std::string& nJson)
{
  json j = json::parse(nJson);
  BaseDeserialize(&j);
  this->Message = j["Message"];
}