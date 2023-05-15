#include "ChargingStrategy.h"

ChargingStrategy::ChargingStrategy() {
    time = 0;
}

void ChargingStrategy::Move(IEntity* entity, double dt) {
    time += dt;
}

bool ChargingStrategy::IsCompleted() {
    return time >= 10;
}
