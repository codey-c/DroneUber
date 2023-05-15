#include "Ufo.h"
#include "AstarStrategy.h"


Ufo::Ufo(const JsonObject& obj) : details(obj) {
  JsonArray pos(obj["position"]);
  position = {pos[0], pos[1], pos[2]};

  JsonArray dir(obj["direction"]);
  direction = {dir[0], dir[1], dir[2]};

  speed = obj["speed"];
  available = true;
}

Ufo::~Ufo() {
  // Delete dynamically allocated variables
}

Vector3 Ufo::SetRandom() {
  float v1 = (std::rand() % 2901) - (2901 / 2);         // v1 in the range
  float v2 = 300;     // v2 in the range
  float v3 = (std::rand() % 1601) - (1601 / 2);   // v3 in the range
  return{v1, v2, v3};
}

void Ufo::Update(double dt, std::vector<IEntity*> scheduler) {
    if (available) {
      destination = Ufo::SetRandom();
      available = false;
      toTargetDestStrategy = new AstarStrategy(position, destination, graph);
    } else if (toTargetDestStrategy) {
    toTargetDestStrategy->Move(this, dt);
    if (toTargetDestStrategy->IsCompleted()) {
        delete toTargetDestStrategy;
        toTargetDestStrategy = NULL;
        available = true;
    }
  }
}
