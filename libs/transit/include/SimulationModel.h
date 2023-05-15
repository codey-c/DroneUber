#ifndef LIBS_TRANSIT_INCLUDE_SIMULATIONMODEL_H_
#define LIBS_TRANSIT_INCLUDE_SIMULATIONMODEL_H_

#include "IController.h"
#include "CompositeFactory.h"
#include "IEntity.h"
#include "graph.h"
using namespace routing;

//--------------------  Model ----------------------------

/**
 * @brief Simulation Model handling the transit simulation.  The model can 
 * communicate with the controller.
 **/
class SimulationModel {
 public:
   /**
    * @brief The constructor for the SimulationModel class.
    * @param controller A reference to a IController type object that the 
    * is used to controllor functionality within the simulation.
    **/
  SimulationModel(IController& controller);

   /**
    * @brief A setter for changing the graph of the model
    * @param graph A IGraph object that the model is to be set to 
    **/
  void SetGraph(const IGraph* graph) { this->graph = graph; }

   /**
    * @brief Creates an entity within the simulation.
    * @param entity A JsonObject that contatins the details of the 
    * entity that is to be created. 
    **/
  void CreateEntity(JsonObject& entity);

   /**
    * @brief Schedules a trip for an object in the scene
    * @param details A JsonObject that contatins the details of the 
    * entity that is to be scheduled.
    **/
  void ScheduleTrip(JsonObject& details);

   /**
    * @brief Updates the simulation.
    * @param dt A double that represents the change in time 
    * of the program
    **/
  void Update(double dt);

   /**
    * @brief Adds a IEntityFactory object to the simulation. 
    * @param factory A pointer to the IEntityFactory object that
    * is to be added to the simulation.
    **/
  void AddFactory(IEntityFactory* factory);

 protected:
  IController& controller;
  std::vector<IEntity*> entities;
  std::vector<IEntity*> scheduler;
  std::vector<IEntity*> rechargeStations;
  const IGraph* graph;
  CompositeFactory* compFactory;
};

#endif  // LIBS_TRANSIT_INCLUDE_SIMULATIONMODEL_H_

