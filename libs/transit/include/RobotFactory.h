#ifndef LIBS_TRANSIT_INCLUDE_ROBOTFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_ROBOTFACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Robot.h"

#include <vector>

/**
 * @brief this class inhertis from the IEntityFactory class and is responsible
 * for creating Robot objects for the simulation. 
 */
class RobotFactory : public IEntityFactory {
 public:
    /**
     * @brief Creates a Robot object.
     * @param entity A JsonObject that contains the details of the 
     * Robot object that is to be created.
     * @return A pointer that point to the new Robot object.
     **/
    IEntity* CreateEntity(const JsonObject& entity);
};

#endif  // LIBS_TRANSIT_INCLUDE_ROBOTFACTORY_H_
