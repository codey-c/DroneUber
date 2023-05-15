#ifndef LIBS_TRANSIT_INCLUDE_CELEBRATIONDECORATOR_H_
#define LIBS_TRANSIT_INCLUDE_CELEBRATIONDECORATOR_H_

#include <vector>

#include "IStrategy.h"

/**
 * @brief this class inhertis from the IStrategy class and is responsible for 
 * implementing the celebration logic. This class is meant to wrap a strategy
 * object and can be wrapped further to implement other celebrations.
 */
class CelebrationDecorator : public IStrategy {
 public:
  /**
   * @brief The constructor for CelebrationDecorator class
   * @param strategy_ A pointer to the strategy that is being wrapped.
   * @return A pointer to the new CelebrationDecorator object.
   **/
  CelebrationDecorator(IStrategy *strategy_) {
    strategy = strategy_;
    time = 0;
  }

  /**
   * @brief The function adjusts time by dt increments and implements the
   * movement logic of the strategy. 
   * @param entity A pointer that points to the IEntity object that is
   * to be moved.
   * @param dt A float that represents the time that is to be added to the
   * time field.
   **/
  void Move(IEntity *entity, double dt);

  /**
   * @brief Checks to see if the strategy has finished implementing its logic.
   * @return A bool that returns true when the strategy is completed.  
   **/
  bool IsCompleted();

 protected:
  IStrategy *strategy;
  float time;
};  // close class

#endif  // LIBS_TRANSIT_INCLUDE_CELEBRATIONDECORATOR_H_
