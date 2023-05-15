#ifndef LIBS_TRANSIT_INCLUDE_DRONEFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_DRONEFACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Drone.h"

#include <vector>

/**
 * @brief this class inhertis from the IEntityFactory class and is responsible
 * for creating Drone objects for the simulation. 
 */
class DroneFactory : public IEntityFactory {
 public:
   /**
    * @brief The Deconstructor for the DroneFactory class.
    **/
    virtual ~DroneFactory() {}

    /**
     * @brief Creates a Drone object.
     * @param entity A JsonObject that contains the details of the 
     * Drone object that is to be created.
     * @return A pointer that point to the new Drone object.
     **/
    IEntity* CreateEntity(const JsonObject& entity);
};

#endif  // LIBS_TRANSIT_INCLUDE_DRONEFACTORY_H_
