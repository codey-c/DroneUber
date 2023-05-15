#ifndef LIBS_TRANSIT_INCLUDE_HELICOPTER_H_
#define LIBS_TRANSIT_INCLUDE_HELICOPTER_H_

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"
#include "IStrategy.h"

class Helicopter : public IEntity {
 public:
  Helicopter(const JsonObject& obj);

  ~Helicopter() override = default;

  Vector3 GetPosition() const { return position; }

  Vector3 GetDirection() const { return direction; }

  Vector3 GetDestination() const { return destination; }

  JsonObject GetDetails() const override;

  float GetSpeed() const { return speed; }

  void SetPosition(Vector3 pos_) { position = pos_; }

  void SetDirection(Vector3 dir_) { direction = dir_; }

  void SetDestination(Vector3 des_) { destination = des_; }

  void Rotate(double angle);

  void Update(double dt, std::vector<IEntity*> scheduler);

  float Random(float Min, float Max);

  void SetNewDestination();

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  IStrategy* strategy = NULL;
  float speed;
};

#endif  // LIBS_TRANSIT_INCLUDE_HELICOPTER_H_

