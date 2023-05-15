#ifndef LIBS_TRANSIT_INCLUDE_CARFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_CARFACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Car.h"

#include <vector>

/**
 * @brief this class inhertis from the IEntityFactory class and is responsible
 * for creating Car objects for the simulation. 
 */
class CarFactory : public IEntityFactory {
 public:
   /**
    * @brief The Deconstructor for the CarFactory class.
    **/
    virtual ~CarFactory() {}

    /**
     * @brief Creates a Car object.
     * @param entity A JsonObject that contains the details of the 
     * Car object that is to be created.
     * @return A pointer that point to the new Car object.
     **/
    IEntity* CreateEntity(const JsonObject& entity);
};

#endif  // LIBS_TRANSIT_INCLUDE_CARFACTORY_H_
