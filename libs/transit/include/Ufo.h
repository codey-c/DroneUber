#ifndef LIBS_TRANSIT_INCLUDE_UFO_H_
#define LIBS_TRANSIT_INCLUDE_UFO_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"
#include "util/json.h"

/**
 * @brief This class inherits from IEntity and makes continuously moving ufo
 */
class Ufo : public IEntity {
 public:
  /**
     * @brief Ufo constructor
     * @param obj Json object with Ufo info
    **/
    Ufo(const JsonObject& obj);

    /**
     * @brief Ufo destructor
     **/
    ~Ufo();

    /** 
     * @brief Gets the speed of the ufo
     * @return A float that represents the ufo's speed
     **/
    float GetSpeed() const { return speed; }

    /**
     * @brief Gets the ufo's position
     * @return A Vetor3 object that contains the position of the ufo
     **/
    Vector3 GetPosition() const { return position; }

    /**
     * @brief Gets the ufo's direction
     * @return A Vetor3 object that contains the direction of the ufo
     **/
    Vector3 GetDirection() const { return direction; }

    /**
     * @brief Gets the ufo's destination
     * @return A Vetor3 object that contains the destination of the ufo
     **/
    Vector3 GetDestination() const { return destination; }

    /**
     * @brief Gets the ufo's details
     * @return A JsonObject that contains the details of the ufo
    **/
    JsonObject GetDetails() const { return details; }

    /**
     * @brief Updates the ufo
     * @param dt A double that represents time pasted between updates
     * @param scheduler A vector containing all instantiated IEntity objects
     * within the similation.
    **/
    void Update(double dt, std::vector<IEntity*> scheduler);

    /**
     * @brief Sets the ufo's position
     * @param pos_ A Vector3 object that contains the new position of the ufo
    **/
    void SetPosition(Vector3 pos_) { position = pos_; }

    /**
     * @brief Sets the ufo's direction
     * @param pos_ A Vector3 object that contains the new direction of the ufo
    **/
    void SetDirection(Vector3 dir_) { direction = dir_; }

    /**
     * @brief Generates a random destination for the ufo
     * @return A Vector3 object that contains the new destination
    **/
    Vector3 SetRandom();

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  float speed;
  bool available;
  IStrategy* toTargetDestStrategy = NULL;
};

#endif  // LIBS_TRANSIT_INCLUDE_UFO_H_
