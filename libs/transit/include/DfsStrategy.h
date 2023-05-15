#ifndef LIBS_TRANSIT_INCLUDE_DFSSTRATEGY_H_
#define LIBS_TRANSIT_INCLUDE_DFSSTRATEGY_H_

#include "math/vector3.h"
#include <vector>
#include "IStrategy.h"
#include "IEntity.h"
/**
 * @brief this class inhertis from the IStrategy class and is responsible for
  generating the beeline that the drone will take.
 */
class DfsStrategy : public IStrategy {
 public:
   /**
    * @brief The constructor for DfsStrategy class
    * @param position Vector3 object that represents the position of the
    * DfsStrategy object.
    * @param destination Vector3 object that represents the destination of the
    * DfsStrategy object.
    * @param graph A pointer to a IGraph* object the represents a graph of the
    * simulation. 
    * @return A pointer to the new DfsStrategy object.
    **/
    DfsStrategy(Vector3 position, Vector3 destination, const IGraph* graph);

   /**
    * @brief The deconstructor for the DfsStrategy class.
    **/
    ~DfsStrategy();

   /**
    * @brief The function adjusts time by dt increments and implements the
    * movement logic of the strategy.  
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
    std::vector<std::vector<float>> path;
    int currentIndex;
    int maxIndex;
};  // end class
#endif  // LIBS_TRANSIT_INCLUDE_DFSSTRATEGY_H_
