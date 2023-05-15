#include "UfoFactory.h"

IEntity* UfoFactory::CreateEntity(const JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("ufo") == 0) {
    std::cout << "Ufo Created" << std::endl;
    return new Ufo(entity);
  }
  return nullptr;
}
