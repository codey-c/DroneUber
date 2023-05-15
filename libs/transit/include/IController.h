#ifndef LIBS_TRANSIT_INCLUDE_ICONTROLLER_H_
#define LIBS_TRANSIT_INCLUDE_ICONTROLLER_H_

#include "IEntity.h"
#include "util/json.h"

//--------------------  Controller Interface ----------------------------
/**
 * Abstract controller class used in the Transit Service.  Uses the Model View
 * Controller Pattern
 **/
class IController {
 public:
    /**
     * @brief Deconstructor for this abstract class.
     */
    virtual ~IController() {}

    /**
     * @brief Adds an entity to the program
     * @param entity A reference to a IEntity object
     */
    virtual void AddEntity(const IEntity& entity) = 0;

    /**
     * @brief Updates an entity to the program
     * @param entity A reference to a IEntity object
     */
    virtual void UpdateEntity(const IEntity& entity) = 0;

    /**
     * @brief Removes an entity from the program
     * @param id The id of the entity that is to be removed.
     */
    virtual void RemoveEntity(int id) = 0;

    /**
     * @brief Adds a path to the program
     * @param id The id of the entity of which path is to be added.
     * @param path A vector of floats representing the path that is
     * to be added.
     **/
    virtual void AddPath(int id,
        const std::vector<std::vector<float> >& path) = 0;

    /**
     * @brief Removes a path from the program
     * @param id The id of the entity of which path is to be removed
     **/
    virtual void RemovePath(int id) = 0;

    /**
     * @brief Allows messages to be passed back to the view
     * @param event The event to be sent
     * @param details A Json Object containing the details to be sent
     **/
    virtual void SendEventToView(const std::string& event,
                               const JsonObject& details) = 0;
};

#endif  // LIBS_TRANSIT_INCLUDE_ICONTROLLER_H_

