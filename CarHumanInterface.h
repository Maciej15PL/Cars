#ifndef UNTITLED_CARHUMANINTERFACE_H
#define UNTITLED_CARHUMANINTERFACE_H

#include "Car.h"

typedef float Distance;

class CarHumanInterface {
private:
    Car* car;   //auto które chcemy obsługiwać
public:
    explicit CarHumanInterface(Car* car);

    void commandLineInterface();    // obsługa za pomocą konsoli

    void status(); // status auta, ile jest paliwa, czy silnik działa, ile jest w bagażniku

    void startEngine(); // uruchamia silnik
    void stopEngine(); // zatrzymuje silnik

    void toggleLights(); // przełącza światła

    void refuel(Liter amount); // tankuje x litrów do zbiornika

    void drive(Distance distance); // jedzie przez określony dystans

    void addPayload(Weight payload); // dodaje masę do bagażnika
    void removePayload(Weight payload); // usuwa --||--
};


#endif //UNTITLED_CARHUMANINTERFACE_H
