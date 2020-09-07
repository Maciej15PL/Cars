#ifndef UNTITLED_BASICCAR_H
#define UNTITLED_BASICCAR_H

#include "Car.h"

class BasicCar : public Car {
private:
    const Weight maximumPayload;
    const Liter fuelCapacity, fuelEfficiency;

    Weight payload{0};
    Liter fuel{0};

    bool lightEnabled{false}, engineEnabled{false};
public:
    BasicCar(Weight maximumPayload, Liter fuelCapacity, Liter fuelEfficiency);

    Weight getMaximumPayload() override;
    Liter getFuelCapacity() override;
    Liter getFuelEfficiency() override;

    Weight getPayload() override;
    void setPayload(Weight weight) override;

    Liter getFuel() override;
    void setFuel(Liter amount) override;

    bool isLightEnabled() override;
    void setLightEnabled(bool enabled) override;

    bool isEngineEnabled() override;
    void setEngineEnabled(bool enabled) override;
};


#endif //UNTITLED_BASICCAR_H
