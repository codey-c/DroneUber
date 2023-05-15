#ifndef LIBS_TRANSIT_INCLUDE_CAR_H_
#define LIBS_TRANSIT_INCLUDE_CAR_H_

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"
#include "IStrategy.h"

/** 
 * @brief Represents a car within the simulation. Cars move using 
 * euler integration based on a specified velocity and direction.
 **/
class Car : public IEntity {
 public:
  /**
   * @brief Constructor for Car class. 
   * @param obj A JsonObject that contatins the details of the new Car object
   * that is being created. 
   **/
  Car(const JsonObject& obj);

  /**
   * @brief Deconstructor for Car class. 
   **/
  ~Car() override = default;

  /**
   * @brief Gets the position of the Car object.
   * @return A Vector3 object that represents the position of the
   * Car object.
   **/
  Vector3 GetPosition() const { return position; }

  /**
   * @brief Gets the direction of the Car object.
   * @return A Vector3 object that represents the direction of the
   * Car object.
   **/
  Vector3 GetDirection() const { return direction; }

  /**
   * @brief Gets the destionation of the Car object.
   * @return A Vector3 object that represents the destionation of the
   * Car object.
   **/
  Vector3 GetDestination() const { return destination; }

  /**
   * @brief Gets the json details of the Car object.
   * @return A JsonObject that contains the details of the
   * Car object.
   **/
  JsonObject GetDetails() const override;

  /**
   * @brief Gets the speed of the Car object.
   * @return A float that represents the speed of the
   * Car object.
   **/
  float GetSpeed() const { return speed; }

  /**
   * @brief Sets the postion of the Car.
   * @param dt A Vector3 object that represents the postion of the
   * Car object.
   **/
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * @brief Sets the direction of the Car.
   * @param dt A Vector3 object that represents the direction of the
   * Car object.
   **/
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * @brief Sets the destination of the Car.
   * @param dt A Vector3 object that represents the destination of the
   * Car object.
   **/
  void SetDestination(Vector3 des_) { destination = des_; }

  /**
   * @brief Rotates the Car.
   * @param angle A double that represents angle of the desired rotation of the
   * Car object.
   **/
  void Rotate(double angle);

  /**
   * @brief Updates the location of the Car by updating the Car objects
   * current strategy.
   * @param dt A float that represents the amount of time passed.
   * @param scheduler A vector of all entities found in the simulation.
   **/
  void Update(double dt, std::vector<IEntity*> scheduler);

  /**
   * @brief Computes a random number that the Car object 
   * will use as a random location to move to. 
   * @param Min A float that represents the lower limit of random number
   * that is to be generated. 
   * @param Max A float that represents the upper limit of random number
   * that is to be generated.
   * @return A random float within the given Min and Max values. 
   **/
  float Random(float Min, float Max);

  /**
   * @brief Uses the Car::Random() function to set a new random location. 
   **/
  void SetNewDestination();

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  IStrategy* strategy = NULL;
  float speed;
};

#endif  // LIBS_TRANSIT_INCLUDE_CAR_H_

