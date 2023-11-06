#pragma once

#include <SynergyCoreExports.h>

#include <json.hpp>
#include <string>

class SYNERGYCORE_API Serializable {
public:
  virtual std::string Serialize() const = 0;
  virtual void Deserialize(const std::string&) = 0;
};
