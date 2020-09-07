#ifndef UNTITLED_CARHUMANINTERFACE_H
#define UNTITLED_CARHUMANINTERFACE_H

#include "Car.h"

typedef float Distance;

class CarHumanInterface {
private:
    Car* car;
public:
    explicit CarHumanInterface(Car* car);

    void commandLineInterface();

    void status();

    void startEngine();
    void stopEngine();

    void toggleLights();

    void refuel(Liter amount);

    void drive(Distance distance);

    void addPayload(Weight payload);
    void removePayload(Weight payload);
};


#endif //UNTITLED_CARHUMANINTERFACE_H
