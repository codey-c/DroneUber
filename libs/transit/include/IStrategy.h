#ifndef LIBS_TRANSIT_INCLUDE_ISTRATEGY_H_
#define LIBS_TRANSIT_INCLUDE_ISTRATEGY_H_

#include <vector>
#include "graph.h"
#include "IEntity.h"

using namespace routing;

/**
 * @brief An abstract strategy class used as the base for other strategy
 * classes.  Strategy class are where certain functionality of a 
 * object is implemented.
 */
class IStrategy {
 public:
   /**
    * @brief The function adjusts time by dt increments and implements the
    * movement logic of the strategy. 
    * @param entity A pointer that points to the IEntity object that is
    * to be moved.
    * @param dt A float that represents the time that is to be added to the
    * time field.
    **/
    virtual void Move(IEntity* entity, double dt) = 0;

   /**
    * @brief Checks to see if the strategy has finished implementing its logic.
    * @return A bool that returns true when the strategy is completed.  
    **/
    virtual bool IsCompleted() = 0;

 protected:
    // IGraph object to be used in the simulation.
    const IGraph* graph;
};  // close class

#endif  // LIBS_TRANSIT_INCLUDE_ISTRATEGY_H_
