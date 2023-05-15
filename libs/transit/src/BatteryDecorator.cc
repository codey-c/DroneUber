#include "BatteryDecorator.h"
#include "ChargingStrategy.h"
#include "BeelineStrategy.h"
// #include "BatteryDisplay.h"
// #include "IController.h"
#include <iostream>
#include <fstream>

BatteryDecorator::BatteryDecorator(IEntity* entity_,
    std::vector<IEntity*> rechargeStations_) {
    rechargeStations = rechargeStations_;
    entity = entity_;
    battery = 100;
    increment = 3;
    color = entity->GetColor();
    std::cout << color << std::endl;
}

bool BatteryDecorator::GetAvailability() {
    return entity->GetAvailability();
}

float BatteryDecorator::GetBatteryPercentage() {
    return battery;
}

void BatteryDecorator::CheckColor() {
    if (battery <= 100 && battery > 80) {
        if (chargeStage != 1) {
            chargeStage = 1;
            color = "#00ff00";
        }
    } else if (battery <= 80 && battery > 60) {
        if (chargeStage != 2) {
            chargeStage = 2;
            color = "#7fff00";
        }
    } else if (battery <= 60 && battery > 40) {
        if (chargeStage != 3) {
            chargeStage = 3;
            color = "#ffff00";
        }
    } else if (battery <= 40 && battery > 20) {
        if (chargeStage != 4) {
            chargeStage = 4;
            color = "#ff7f00";
        }
    } else if (battery < 20) {
        if (chargeStage != 5) {
            chargeStage = 5;
            color = "#ff0000";
        }
    }
}

void BatteryDecorator::Update(double dt, std::vector<IEntity*> scheduler) {
    // batteryDisplay->SetPosition(this->GetPosition());
    // batteryDisplay->SetDirection(this->GetDirection());
    BatteryDecorator::CheckColor();
    if (increment >= 3) {
        std::ofstream batteryFile;
        batteryFile.open("apps/transit_service/web/battery.txt");
        batteryFile << std::to_string(battery);
        batteryFile.close();
        increment = 0;
    }
    increment += (5 * dt);

    // moving to recharge station
    if (toRechargeStationStrategy != NULL) {
        battery -= (.2* dt);
        toRechargeStationStrategy->Move(this, dt);
        if (toRechargeStationStrategy->IsCompleted()) {
            delete toRechargeStationStrategy;
            toRechargeStationStrategy = NULL;
        }
    } else if (chargingStrategy != NULL) {
        // at recharge station and charging robot,
        // stays at recharge station a few seconds
        chargingStrategy->Move(this, dt);
        if (chargingStrategy->IsCompleted()) {
            delete chargingStrategy;
            chargingStrategy = NULL;
            nearestRechargeStation = NULL;
            battery = 100;
            std::ofstream batteryFile;
            batteryFile.open("apps/transit_service/web/battery.txt");
            batteryFile << std::to_string(battery);
            batteryFile.close();
            increment = 0;
            increment = 3;
        }
    } else if ((entity->GetAvailability()) && (battery <= 50)) {
        // low battery, find nearest charging station
        // want to recharge when not transporting a robot
        battery -= (0.2 * dt);
        GetNearestRechargeStation(scheduler);
    } else {
        // battery is not low, continue as normal
        // entity is not available - moving
        if (!entity->GetAvailability()) {
            battery -= (.2* dt);
        }
        entity->Update(dt, scheduler);
    }
}

void BatteryDecorator::SetPosition(Vector3 pos_) {
    entity->SetPosition(pos_);
}

void BatteryDecorator::SetDirection(Vector3 dir_) {
    entity->SetDirection(dir_);
}

void BatteryDecorator::SetDestination(Vector3 des_) {
    entity->SetDirection(des_);
}

void BatteryDecorator::SetStrategyName(std::string strategyName_) {
    entity->SetStrategyName(strategyName_);
}

void BatteryDecorator::Rotate(double angle) {
    entity->Rotate(angle);
}

void BatteryDecorator::Jump(double height) {
    entity->Jump(height);
}

void BatteryDecorator::GetNearestEntity(std::vector<IEntity*> scheduler) {
    entity->GetNearestEntity(scheduler);
}

void BatteryDecorator::GetNearestRechargeStation(std::vector<IEntity*>
    scheduler) {

    float minDis = std::numeric_limits<float>::max();
    for (auto station : rechargeStations) {
        float disToEntity =
            this->GetPosition().Distance(station->GetPosition());
        if (disToEntity <= minDis) {
            minDis = disToEntity;
            nearestRechargeStation = station;
        }
    }

    toRechargeStationStrategy = new BeelineStrategy(this->GetPosition(),
        nearestRechargeStation->GetPosition());
    chargingStrategy = new ChargingStrategy();
}
