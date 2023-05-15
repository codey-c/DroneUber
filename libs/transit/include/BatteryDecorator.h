#ifndef LIBS_TRANSIT_INCLUDE_BATTERYDECORATOR_H_
#define LIBS_TRANSIT_INCLUDE_BATTERYDECORATOR_H_

#include "IEntity.h"
#include "IStrategy.h"
#include "IController.h"

/**
 * @brief A decorator class that wraps the Drone objects.
 * This adds battery functionality.
 **/
class BatteryDecorator : public IEntity {
 public:
  /**
   * @brief The constructor for BatteryDecorator class
   * @param entity_ A pointer to the Drone that is being wrapped.
   * @param rechargeStations_ A vector of all the recharge stations found
   * in the simulation.
   * @return A pointer to the new BatteryDecorator object.
   **/    
  BatteryDecorator(IEntity *entity_, std::vector<IEntity*> rechargeStations_);

  /**
   * @brief Gets the position of the BatteryDecorator object.
   * @return A Vector3 object that represents the position of the
   * batteryDecorator object.
   **/
  Vector3 GetPosition() const { return entity->GetPosition(); }

  /**
   * @brief Gets the direction of the BatteryDecorator object.
   * @return A Vector3 object that represents the direction of the
   * BatteryDecorator object.
   **/
  Vector3 GetDirection() const { return entity->GetDirection(); }

  /**
   * @brief Gets the destionation of the BatteryDecorator object.
   * @return A Vector3 object that represents the destionation of the
   * BatteryDecorator object.
   **/
  Vector3 GetDestination() const { return entity->GetDestination(); }

  /**
   * @brief Gets the json details of the BatteryDecorator object.
   * @return A JsonObject that contains the details of the
   * batteryDecorator object.
   **/
  JsonObject GetDetails() const { return entity->GetDetails(); }

  /**
   * @brief Gets the availability of the BatteryDecorator object.
   * @return A bool that represents the availability of the
   * batteryDecorator object.
   **/
  bool GetAvailability();

  /**
   * @brief Gets the speed of the BatteryDecorator object.
   * @return A float that represents the speed of the
   * batteryDecorator object.
   **/
  float GetSpeed() const { return entity->GetSpeed(); }

  /**
   * @brief Gets the percentage of the BatteryDecorator object's battery charge.
   * @return A float that represents the percentage of battery left in the
   * batteryDecorator object.
   **/
  float GetBatteryPercentage();

  /**
   * @brief Gets the color of the BatteryDecorator object.
   * @return A strin that represents the color of the
   * batteryDecorator object.
   **/
  std::string GetColor() const {return color;}

  /**
   * @brief Checks the charge of the BatteryDecorator's battery and adjusts
   * the color of the BatteryDecorator accordingly.
   **/
  void CheckColor();

  /**
   * @brief Updates the batteries current charge.  Updates the
   * BatteryDecorators strategy depending on batteries charge.
   * @param dt A float that represents the amount of time passed.
   * @param scheduler A vector of all entities found in the simulation.
   **/ 
  void Update(double dt, std::vector<IEntity*> scheduler);

  /**
   * @brief Sets the postion of the BatteryDecorator.
   * @param dt A Vector3 object that represents the postion of the
   * BatteryDecorator object.
   **/ 
  void SetPosition(Vector3 pos_);

  /**
   * @brief Sets the direction of the BatteryDecorator.
   * @param dt A Vector3 object that represents the direction of the
   * BatteryDecorator object.
   **/ 
  void SetDirection(Vector3 dir_);

  /**
   * @brief Sets the destination of the BatteryDecorator.
   * @param dt A Vector3 object that represents the destination of the
   * BatteryDecorator object.
   **/ 
  void SetDestination(Vector3 des_);

  /**
   * @brief Sets the strategy of the BatteryDecorator.
   * @param strategyName_ A string that represents the desired strategy of the
   * BatteryDecorator object.
   **/
  void SetStrategyName(std::string strategyName_);

  /**
   * @brief Rotates the BatteryDecorator.
   * @param angle A double that represents angle of the desired rotation of the
   * BatteryDecorator object.
   **/
  void Rotate(double angle);

  /**
   * @brief Simulates a jumping motion of the BatteryDecorator within
   * the simulation.
   * @param height A double that represents the desired height of the 
   * BatteryDecorator's jump.
   **/
  void Jump(double height);

  /**
   * @brief Gets the nearest available entity by iteration the scheduler.
   * @param scheduler A vector of all entities within the simulation.
   **/
  void GetNearestEntity(std::vector<IEntity*> scheduler);

  /**
   * @brief Gets the nearest recharge station by iteration of a vector
   * that contains all recharge stations within the simulation.
   * @param scheduler A vector of all recharge stations within the simulation.
   **/
  void GetNearestRechargeStation(std::vector<IEntity*> scheduler);

 protected:
    IEntity *entity;
    float battery;
    int chargeStage = 0;
    std::string color = "#00ff00";
    std::vector<IEntity*> rechargeStations;
    IEntity* nearestRechargeStation = NULL;
    IStrategy* toRechargeStationStrategy = NULL;
    IStrategy* chargingStrategy = NULL;
    float increment;
};

#endif  // LIBS_TRANSIT_INCLUDE_BATTERYDECORATOR_H_
