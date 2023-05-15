#ifndef LIBS_TRANSIT_INCLUDE_SPINDECORATOR_H_
#define LIBS_TRANSIT_INCLUDE_SPINDECORATOR_H_

#include <vector>

#include "CelebrationDecorator.h"
#include "IStrategy.h"

/**
 * @brief this class inhertis from the Celebration class and contains the logic
 * for spinning celebration.  This is a wrapper class. 
 */
class SpinDecorator : public CelebrationDecorator {
 public:
  /**
   * @brief The constructor for SpinDecorator class
   * @param strategy_ A pointer to the strategy that is being wrapped.
   * @return A pointer to the new SpinDecorator object.
   **/
  SpinDecorator(IStrategy* strategy_) : CelebrationDecorator(strategy_) {}

  /**
   * @brief Checks to see if the strategy has finished implementing its logic.
   * @return A bool that returns true when the strategy is completed.  
   **/
  bool IsCompleted();

  /**
   * @brief The function adjusts time by dt increments and implements the
   * movement logic of the strategy. 
   * @param entity A pointer that points to the IEntity object that is
   * to be moved.
   * @param dt A float that represents the time that is to be added to the
   * time field.
   **/ 
  void Move(IEntity* entity, double dt);
};  // close class

#endif  // LIBS_TRANSIT_INCLUDE_SPINDECORATOR_H_
