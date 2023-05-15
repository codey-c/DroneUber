#ifndef LIBS_TRANSIT_INCLUDE_RECHARGESTATION_H_
#define LIBS_TRANSIT_INCLUDE_RECHARGESTATION_H_

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"

/**
 * @brief A class that represent a charger that the drone uses to recharge 
 * its battery charge.
 **/
class RechargeStation : public IEntity {
 public:
  /**
   * @brief The constructor for RechargeStation class
   * @param obj A JsonObject& containing the detatils of the RechargeStation
   * @return A pointer to the new RechargeStation object.
   **/
  RechargeStation(const JsonObject& obj);

  /**
   * @brief The deconstructor for RechargeStation class
   **/
  ~RechargeStation() override = default;

  /**
   * @brief Gets the position of the RechargeStation object.
   * @return A Vector3 object that represents the position of the
   * RechargeStation object.
   **/
  Vector3 GetPosition() const { return position; }

  /**
   * @brief Gets the direction of the RechargeStation object.
   * @return A Vector3 object that represents the direction of the
   * RechargeStation object.
   **/
  Vector3 GetDirection() const { return direction; }

  /**
   * @brief Gets the destionation of the RechargeStation object.
   * @return A Vector3 object that represents the destionation of the
   * RechargeStation object.
   **/
  Vector3 GetDestination() const { return destination; }

  /**
   * @brief Gets the availability of the RechargeStation object.
   * @return A bool that represents the availability of the
   * RechargeStation object.
   **/
  bool GetAvailability() const { return available; }

  /**
   * @brief Gets the json details of the RechargeStation object.
   * @return A JsonObject that contains the details of the
   * RechargeStation object.
   **/
  JsonObject GetDetails() const override;

  /**
   * @brief Gets the speed of the RechargeStation object.
   * @return A float that represents the speed of the
   * RechargeStation object.
   **/
  float GetSpeed() const { return speed; }

  /**
   * @brief Sets the availability of the RechargeStation object/.
   * @param choice A bool that represents the new desired availability of the
   * RechargeStation object.
   **/
  void SetAvailability(bool choice);

  /**
   * @brief Sets the postion of the RechargeStation.
   * @param dt A Vector3 object that represents the postion of the
   * RechargeStation object.
   **/
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * @brief Sets the direction of the RechargeStation.
   * @param dt A Vector3 object that represents the direction of the
   * RechargeStation object.
   **/ 
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * @brief Sets the destination of the RechargeStation.
   * @param dt A Vector3 object that represents the destination of the
   * RechargeStation object.
   **/ 
  void SetDestination(Vector3 des_) { destination = des_; }

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  float speed;
  bool available;
};

#endif  // LIBS_TRANSIT_INCLUDE_RECHARGESTATION_H_
