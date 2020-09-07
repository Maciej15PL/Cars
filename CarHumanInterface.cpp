#include "CarHumanInterface.h"

#include <iostream>
#include <algorithm>

CarHumanInterface::CarHumanInterface(Car *car) :
    car{car} {}

void CarHumanInterface::commandLineInterface() {
    bool running = true;
    std::string action;

    while (running) {
        std::cout << "Co chcesz zrobic? [wyjscie, status, start, stop, swiatla, tankuj, jedz, zaladuj, rozladuj]: ";
        std::cin >> action;

        try {   //jeżeli jakaś funkcja się nie powiedzie wyrzuci bład który zostanie złapany
            if (action == "wyjscie") {
                running = false;
            } else if (action == "status") {
                this->status();
            } else if (action == "start") {
                this->startEngine();
            } else if (action == "stop") {
                this->stopEngine();
            } else if (action == "swiatla") {
                this->toggleLights();
            } else if (action == "tankuj") {
                Liter amount;
                std::cout << "Ile litrow chcesz zatankowac?" << std::endl;
                std::cin >> amount;

                this->refuel(amount);
            } else if (action == "jedz") {
                Distance distance;
                std::cout << "Ile km chcesz jechac? ";
                std::cin >> distance;

                this->drive(distance);
            } else if (action == "zaladuj") {
                Weight weight;
                std::cout << "Ile chcesz zaladowac do bagaznika?" << std::endl;
                std::cin >> weight;

                this->addPayload(weight);
            } else if (action == "rozladuj") {
                Weight weight;
                std::cout << "Ile chcesz rozladowac z bagaznika?" << std::endl;
                std::cin >> weight;

                this->removePayload(weight);
            }

            std::cout << "Gotowe!" << std::endl;
        } catch (std::runtime_error& error) {   // i wyświetlone zostanie co dokładnie poszło nie tak
            std::cout << "Blad: " << error.what() << std::endl;
        }
    }
}

void CarHumanInterface::status() {
    std::cout << "Status samochodu: " << std::endl <<
        "Poziom paliwa: " << this->car->getFuel() << "/" << this->car->getFuelCapacity() << "l " << std::endl <<
        "Waga ladunku: " << this->car->getPayload() << "/" << this->car->getMaximumPayload() << "kg" << std::endl <<
        "Swiatla: " << (this->car->isLightEnabled() ? "wlaczone" : "wylaczone") << std::endl <<
        "Silnik: " << (this->car->isEngineEnabled() ? "wlaczony" : "wylaczony") << std::endl;
}

void CarHumanInterface::startEngine() {
    if (this->car->isEngineEnabled())
        throw std::runtime_error{"Silnik jest juz wlaczony"};

    if (this->car->getFuel() == 0)
        throw std::runtime_error{"Brak paliwa"};

    this->car->setEngineEnabled(true);
}

void CarHumanInterface::stopEngine() {
    if (!this->car->isEngineEnabled())
        throw std::runtime_error{"Silnik jest juz wylaczony"};

    this->car->setEngineEnabled(false);
}

void CarHumanInterface::toggleLights() {
    this->car->setLightEnabled(!this->car->isLightEnabled());
}

void CarHumanInterface::refuel(Liter amount) {
    Liter newFuel = this->car->getFuel() + amount;

    if (newFuel > this->car->getFuelCapacity())
        throw std::runtime_error{"Nie mozna zatankowac az tyle paliwa"};

    this->car->setFuel(newFuel);
}

void CarHumanInterface::drive(Distance distance) {
    if (!this->car->isEngineEnabled())
        throw std::runtime_error{"Nie mozna jechac z wylaczonym silnikiem"};

    Liter fuelRequired = this->car->getFuelEfficiency() / 100.0 * distance;
    Liter newFuel = this->car->getFuel() - fuelRequired;

    if (newFuel < 0)
        throw std::runtime_error{"Za malo paliwa by jechac taki dystans!"};

    this->car->setFuel(newFuel);
}

void CarHumanInterface::addPayload(Weight payload) {
    Weight newWeight = this->car->getPayload() + payload;

    if (newWeight > this->car->getMaximumPayload())
        throw std::runtime_error{"Ladunek jest za ciezki"};

    this->car->setPayload(newWeight);
}

void CarHumanInterface::removePayload(Weight payload) {
    Weight newWeight = this->car->getPayload() - payload;

    if (newWeight < 0)
        throw std::runtime_error{"Nie mozna az tyle usunac"};

    this->car->setPayload(newWeight);
}


