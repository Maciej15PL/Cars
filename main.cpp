#include "CarHumanInterface.h"
#include "BasicCar.h"

int main() {
    Car* car = new BasicCar(500, 35, 5.65);
        // tworzymy podstawowe auto z 500kg ladownością 35 litrowym zbiornikiem
        // i wydajnością wynoszącą 5.65

    CarHumanInterface humanInterface{car};  //ta klasa umożliwia obsługę auta przez człowieka
    humanInterface.commandLineInterface();

    return 0;
}