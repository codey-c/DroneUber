#ifndef LIBS_TRANSIT_INCLUDE_CHARGINGSTRATEGY_H_
#define LIBS_TRANSIT_INCLUDE_CHARGINGSTRATEGY_H_

#include "math/vector3.h"
#include <vector>
#include "IStrategy.h"
#include "IEntity.h"
/**
 * @brief this class inhertis from the IStrategy class and is responsible for
 * keeping the drone at the charging station for a few seconds
 */
class ChargingStrategy : public IStrategy {
 public:
   /**
    * @brief The constructor for ChargingStrategy class
    * @return A pointer to the new ChargingStrategy object.
    **/
  ChargingStrategy();

   /**
    * @brief The function adjusts time by dt increments to implement the
    * movement of the entity. 
    * @param entity A pointer that points to the IEntity object that is
    * to be moved.
    * @param dt A float that represents the time that is to be added to the
    * time field.
    **/
  void Move(IEntity* entity, double dt);

   /**
    * @brief Checks to see if the strategy has finished implementing its logic.
    * @return A bool that returns true when the strategy is completed.  
    **/
  bool IsCompleted();

 private:
  float time;
};

#endif  // LIBS_TRANSIT_INCLUDE_CHARGINGSTRATEGY_H_
