#include "BasicCar.h"

BasicCar::BasicCar(Weight maximumPayload, Liter fuelCapacity, Liter fuelEfficiency) :
    maximumPayload{maximumPayload},
    fuelCapacity{fuelCapacity},
    fuelEfficiency{fuelEfficiency} {}

Weight BasicCar::getMaximumPayload() {
    return this->maximumPayload;
}

Liter BasicCar::getFuelCapacity() {
    return this->fuelCapacity;
}

Liter BasicCar::getFuelEfficiency() {
    return this->fuelEfficiency;
}

Weight BasicCar::getPayload() {
    return this->payload;
}

void BasicCar::setPayload(Weight weight) {
    this->payload = weight;
}

Liter BasicCar::getFuel() {
    return this->fuel;
}

void BasicCar::setFuel(Liter amount) {
    this->fuel = amount;
}

bool BasicCar::isLightEnabled() {
    return this->lightEnabled;
}

void BasicCar::setLightEnabled(bool enabled) {
    this->lightEnabled = enabled;
}

bool BasicCar::isEngineEnabled() {
    return this->engineEnabled;
}

void BasicCar::setEngineEnabled(bool enabled) {
    this->engineEnabled = enabled;
}

