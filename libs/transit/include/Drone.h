#ifndef LIBS_TRANSIT_INCLUDE_DRONE_H_
#define LIBS_TRANSIT_INCLUDE_DRONE_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

// Represents a drone in a physical system.
// Drones move using euler integration based on a specified
// velocity and direction.
class Drone : public IEntity {
 public:
  /**
   * @brief Constructor for Drone class. 
   * @param obj A JsonObject that contatins the details of the new Drone object
   * that is being created. 
   **/
  Drone(const JsonObject& obj);

  /**
   * @brief Deconstructor for Drone class. 
   **/
  ~Drone();

  /**
   * @brief Gets the speed of the Drone object.
   * @return A float that represents the speed of the
   * Drone object.
   **/
  float GetSpeed() const { return speed; }

  /**
   * @brief Gets the position of the Drone object.
   * @return A Vector3 object that represents the position of the
   * Drone object.
   **/
  Vector3 GetPosition() const { return position; }

  /**
   * @brief Gets the direction of the Drone object.
   * @return A Vector3 object that represents the direction of the
   * Drone object.
   **/
  Vector3 GetDirection() const { return direction; }

  /**
   * @brief Gets the destionation of the Drone object.
   * @return A Vector3 object that represents the destionation of the
   * Drone object.
   **/
  Vector3 GetDestination() const { return destination; }

  /**
   * @brief Gets the color of the Drone object.
   * @return A string containing the color of the Drone object. Returns 
   * "None" if the color is not set.
   **/
  std::string GetColor() const { return color; }

  /**
   * @brief Gets the json details of the Drone object.
   * @return A JsonObject that contains the details of the
   * Drone object.
   **/
  JsonObject GetDetails() const { return details; }

  /**
   * @brief Gets the availabiliy of the Drone object. 
   * @return A bool representing whether the drone is available or not
   **/
  bool GetAvailability() const { return available; }

  /**
   * @brief Gets the nearest available entity by iterating scheduler. Sets this
   * objects nearestEntity field the entity found. 
   * @param scheduler A Vector of all entities in the simulation.
   **/
  void GetNearestEntity(std::vector<IEntity*> scheduler);

  /**
   * @brief Updates the location of the Drone by updating the Drone objects
   * current strategy.
   * @param dt A float that represents the amount of time passed.
   * @param scheduler A vector of all entities found in the simulation.
   **/
  void Update(double dt, std::vector<IEntity*> scheduler);

  /**
   * @brief Sets the postion of the Drone.
   * @param dt A Vector3 object that represents the postion of the
   * Drone object.
   **/
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * @brief Sets the direction of the Drone.
   * @param dt A Vector3 object that represents the direction of the
   * Drone object.
   **/
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * @brief Sets the destination of the Drone.
   * @param dt A Vector3 object that represents the destination of the
   * Drone object.
   **/
  void SetDestination(Vector3 des_) { destination = des_; }

  /**
   * @brief Rotates the Drone.
   * @param angle A double that represents angle of the desired rotation of the
   * Drone object.
   **/
  void Rotate(double angle);

  /**
   * @brief Simulates jumping of the Drone object. 
   * @param height A double that represents the height of the jump.
   **/
  void Jump(double height);

  // Removing the copy constructor and assignment operator
  // so that drones cannot be coppied.
  Drone(const Drone& drone) = delete;
  Drone& operator=(const Drone& drone) = delete;

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  std::string color = "#00ff00";  // None means default color
  float jumpHeight = 0;
  bool goUp = true;  // jump helper
  Vector3 destination;
  float speed;
  bool available;
  bool pickedUp;
  std::string strategyName;
  IEntity* nearestEntity = NULL;
  IStrategy* toTargetPosStrategy = NULL;
  IStrategy* toTargetDestStrategy = NULL;
};

#endif  // LIBS_TRANSIT_INCLUDE_DRONE_H_

