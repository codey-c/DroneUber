#ifndef LIBS_TRANSIT_INCLUDE_RECHARGESTATIONFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_RECHARGESTATIONFACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "RechargeStation.h"

#include <vector>

/**
 * @brief this class inhertis from the IEntityFactory class and is responsible
 * for creating RechargeStation objects for the simulation. 
 */
class RechargeStationFactory : public IEntityFactory {
 public:
  /**
   * @brief Creates a RechargeStation object.
   * @param entity A JsonObject that contains the details of the 
   * RechargeStation object that is to be created.
   * @return A pointer that point to the new RechargeStation object.
   **/
    IEntity* CreateEntity(const JsonObject& entity);
};

#endif  // LIBS_TRANSIT_INCLUDE_RECHARGESTATIONFACTORY_H_
