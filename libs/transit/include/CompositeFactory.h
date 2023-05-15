#ifndef LIBS_TRANSIT_INCLUDE_COMPOSITEFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_COMPOSITEFACTORY_H_

#include "IEntityFactory.h"

/**
 * @brief this class inhertis from the IEntityFactory class and is responsible
 * for creating grouping together IEntityFactory objects and operating them
 * all at the same time. 
 */
class CompositeFactory : public IEntityFactory {
 public:
   /**
    * @brief The constructor for the CompositeFactory class.
    **/
    IEntity* CreateEntity(const JsonObject& entity);

   /**
    * @brief Takes a IEntityFactory type object and adds it to this object's
    * componentFactories field.
    * @param factoryEntity A pointer to the entity that is to be added. 
    **/
    void AddFactory(IEntityFactory* factoryEntity);

   /**
    * @brief The Deconstructor for the CompositeFactory class.
    **/
    virtual ~CompositeFactory();

 private:
    std::vector<IEntityFactory*> componentFactories;
};

#endif  // LIBS_TRANSIT_INCLUDE_COMPOSITEFACTORY_H_
