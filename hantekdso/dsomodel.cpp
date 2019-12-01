
// SPDX-License-Identifier: GPL-2.0+

#include "dsomodel.h"
#include "modelregistry.h"

DSOModel::DSOModel(int id, unsigned vendorID, unsigned productID, 
                   unsigned vendorIDnoFirmware, unsigned productIDnoFirmware,
                   unsigned firmwareVersion,
                   const std::string &firmwareToken, const std::string &name,
                   const Dso::ControlSpecification &&specification)
    : ID(id), vendorID(vendorID), productID(productID), 
      vendorIDnoFirmware(vendorIDnoFirmware), productIDnoFirmware(productIDnoFirmware), 
      firmwareVersion(firmwareVersion),
      firmwareToken(firmwareToken), name(name), specification(specification) {
    ModelRegistry::get()->add(this);
}
