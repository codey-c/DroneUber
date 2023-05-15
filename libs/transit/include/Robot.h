#ifndef LIBS_TRANSIT_INCLUDE_ROBOT_H_
#define LIBS_TRANSIT_INCLUDE_ROBOT_H_

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"

/**
 * @brief Represents a robot within the simulation. Robots are picked
 * up and moved by drones. 
 **/
class Robot : public IEntity {
 public:
  /**
   * @brief Constructor for Robot class. 
   * @param obj A JsonObject that contatins the details of the new Robot object
   * that is being created. 
   **/
  Robot(const JsonObject& obj);

  /**
   * @brief Deconstructor for Robot class. 
   **/
  ~Robot() override = default;

  /**
   * @brief Gets the position of the Robot object.
   * @return A Vector3 object that represents the position of the
   * Robot object.
   **/
  Vector3 GetPosition() const { return position; }

  /**
   * @brief Gets the direction of the Robot object.
   * @return A Vector3 object that represents the direction of the
   * Robot object.
   **/
  Vector3 GetDirection() const { return direction; }

  /**
   * @brief Gets the destionation of the Robot object.
   * @return A Vector3 object that represents the destionation of the
   * Robot object.
   **/
  Vector3 GetDestination() const { return destination; }

  /**
   * @brief Gets the availabiliy of the Robot object. 
   * @return A bool representing whether the Robot is available or not
   **/
  bool GetAvailability() const { return available; }

  /**
   * @brief Gets the json details of the Robot object.
   * @return A JsonObject that contains the details of the
   * Robot object.
   **/
  JsonObject GetDetails() const override;

  /**
   * @brief Gets the speed of the Robot object.
   * @return A float that represents the speed of the
   * Robot object.
   **/
  float GetSpeed() const { return speed; }

  /**
   * @brief Gets the current strategy of the robot.  
   **/
  std::string GetStrategyName() {return strategyName;}

  /**
   * @brief Sets the availabiliy of the robot. 
   * @param choice A bool representing whether the robot is available or not
   **/
  void SetAvailability(bool choice);

  /**
   * @brief Sets the postion of the Robot.
   * @param dt A Vector3 object that represents the postion of the
   * Robot object.
   **/
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * @brief Sets the direction of the Robot.
   * @param dt A Vector3 object that represents the direction of the
   * Robot object.
   **/
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * @brief Sets the destination of the Robot.
   * @param dt A Vector3 object that represents the destination of the
   * Robot object.
   **/
  void SetDestination(Vector3 des_) { destination = des_; }

  /**
   * @brief Sets the robot's strategy field to the given strategy.
   * @param strategy_ A IStrategy type that represents the strategy that
   * the robot is to implement. 
   **/
  void SetStrategyName(std::string strategyName_)
    { strategyName = strategyName_;}

  /**
   * @brief Rotates the Robot.
   * @param angle A double that represents angle of the desired rotation of the
   * Robot object.
   **/
  void Rotate(double angle);

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  float speed;
  bool available;
  std::string strategyName;
};

#endif  // LIBS_TRANSIT_INCLUDE_ROBOT_H_

