#include "CarHumanInterface.h"
#include "BasicCar.h"

int main() {
    Car* car = new BasicCar(500, 35, 5.65);

    CarHumanInterface humanInterface{car};
    humanInterface.commandLineInterface();

    return 0;
}