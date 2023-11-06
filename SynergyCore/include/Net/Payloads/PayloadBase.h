#pragma once

#include <SynergyCoreExports.h>

#include <Interfaces/Serializable.h>
#include <SynergyCoreExports.h>
#include "PayloadTypes.h"

class SYNERGYCORE_API PayloadBase : public Serializable {
public: 
  PayloadBase(PayloadType nType)
    : Type(nType) {}

  virtual std::string Serialize() const override = 0;
  virtual void Deserialize(const std::string&) override = 0;

  PayloadType Type = PayloadType::NONE;
};