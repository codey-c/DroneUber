#include "RechargeStationFactory.h"

IEntity* RechargeStationFactory::CreateEntity(const JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("recharge") == 0) {
    std::cout << "RechargeStation Created" << std::endl;
    return new RechargeStation(entity);
  }
  return nullptr;
}
