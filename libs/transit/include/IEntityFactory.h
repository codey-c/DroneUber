#ifndef LIBS_TRANSIT_INCLUDE_IENTITYFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_IENTITYFACTORY_H_

#include "util/json.h"

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Drone.h"

/**
 * @brief An abstract factory class used as the base for other factory classes.
 */
class IEntityFactory {
 public:
   /**
    * @brief The Deconstructor for the CarFactory class.
    **/
    virtual ~IEntityFactory() {}

    /**
     * @brief Creates a IEntity object.
     * @param entity A JsonObject that contains the details of the 
     * IEntity object that is to be created.
     * @return A pointer that point to the new IEntity object.
     **/
    virtual IEntity* CreateEntity(const JsonObject& entity) = 0;
};

#endif  // LIBS_TRANSIT_INCLUDE_IENTITYFACTORY_H_
