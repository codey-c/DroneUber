#ifndef LIBS_TRANSIT_INCLUDE_UFOFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_UFOFACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Ufo.h"

#include <vector>

/**
 * @brief Inherits from IEntityFactory, used to create Ufo objects
 **/
class UfoFactory : public IEntityFactory {
 public:
    /**
     * @brief CarFactory contructor
    **/
    virtual ~UfoFactory() {}

    /**
     * @brief creates a new Ufo entity
     * @param entity the JsonObject reference containing information about
     * new entity
     **/
    IEntity* CreateEntity(const JsonObject& entity);
};

#endif  // LIBS_TRANSIT_INCLUDE_UFOFACTORY_H_
