#ifndef LIBS_TRANSIT_INCLUDE_IENTITY_H_
#define LIBS_TRANSIT_INCLUDE_IENTITY_H_

#include <vector>

#include "graph.h"
#include "math/vector3.h"
#include "util/json.h"

using namespace routing;

//--------------------  Controller Interface ----------------------------

/** 
 * @brief Represents a entity within the simulation. This is an interface that
 * is to be used as the base of any entity going into the simulation. 
 **/
class IEntity {
 public:
  /**
   * @brief Constructor for IEntity class. 
   * @param obj A JsonObject that contatins the details of the new IEntity object
   * that is being created. 
   **/
  IEntity() {
    static int currentId = 0;
    id = currentId;
    currentId++;
  }

  /**
   * @brief Deconstructor for IEntity class. 
   **/
  virtual ~IEntity() {}

  /**
   * @brief Gets the ID of the IEntity object. 
   * @return An int that represents the ID of the IEntity object. 
   **/
  virtual int GetId() const { return id; }

  /**
   * @brief Gets the position of the IEntity object.
   * @return A Vector3 object that represents the position of the entity.
   **/
  virtual Vector3 GetPosition() const = 0;

  /**
   * @brief Gets the direction of the IEntity object.
   * @return A Vector3 object that represents the direction of the entity.
   **/
  virtual Vector3 GetDirection() const = 0;

  /**
   * @brief Gets the destionation of the IEntity object.
   * @return A Vector3 object that represents the destionation of the
   * IEntity object.
   **/
  virtual Vector3 GetDestination() const = 0;

  /**
   * @brief Gets the json details of the IEntity object.
   * @return A JsonObject that contains the details of the entity.
   **/
  virtual JsonObject GetDetails() const = 0;

  /**
   * @brief Gets the color of the entity.
   * @return A string containing the color of the entity. Returns 
   * "None" if the color is not set.
   **/
  virtual std::string GetColor() const { return "None"; }

  /**
   * @brief Gets the speed of the IEntity object.
   * @return A float that represents the speed of the
   * IEntity object.
   **/
  virtual float GetSpeed() const = 0;

  /**
   * @brief Gets the availabiliy of the entity. 
   * @return A bool representing whether the entity is available or not
   **/
  virtual bool GetAvailability() const {}

  /**
   * @brief Gets the current strategy of the entity.  
   **/
  virtual std::string GetStrategyName() {}

  /**
   * @brief Sets the availabiliy of the entity. 
   * @param choice A bool representing whether the entity is available or not
   **/
  virtual void SetAvailability(bool choice) {}

  /**
   * @brief Updates the location of the entity since the last dt time. 
   * @param dt A float that represents the amount of time passed.
   * @param scheduler A vector of all entities found in the simulation.
   **/ 
  virtual void Update(double dt, std::vector<IEntity*> scheduler) {}

  /**
   * @brief A setter for changing the graph of the entity
   * @param graph A IGraph object that the entity's graph field is to be set to
   **/
  void SetGraph(const IGraph* graph) { this->graph = graph; }

  /**
   * @brief Sets the postion of the entity.
   * @param dt A Vector3 object that represents the postion of the
   * entity object.
   **/
  virtual void SetPosition(Vector3 pos_) {}

  /**
   * @brief Sets the direction of the entity.
   * @param dt A Vector3 object that represents the direction of the
   * entity object.
   **/
  virtual void SetDirection(Vector3 dir_) {}

  /**
   * @brief Sets the destination of the entity.
   * @param dt A Vector3 object that represents the destination of the
   * entity object.
   **/
  virtual void SetDestination(Vector3 des_) {}

  /**
   * @brief Sets the entity's strategy field to the given strategy.
   * @param strategy_ A IStrategy type that represents the strategy that
   * the entity is to implement. 
   **/
  virtual void SetStrategyName(std::string strategyName_) {}

  /**
   * @brief Rotates the entity.
   * @param angle A double that represents angle of the desired rotation of the
   * entity object.
   **/
  virtual void Rotate(double angle) {}

  /**
   * @brief Simulates jumping of the entity object. 
   * @param height A double that represents the height of the jump.
   **/
  virtual void Jump(double height) {}

  /**
   * @brief Gets the nearest available entity by iterating scheduler. Sets this
   * objects nearestEntity field the entity found. 
   * @param scheduler A Vector of all entities in the simulation.
   **/
  virtual void GetNearestEntity(std::vector<IEntity*> scheduler) {}

 protected:
  int id;
  const IGraph* graph;
};

#endif  // LIBS_TRANSIT_INCLUDE_IENTITY_H_

