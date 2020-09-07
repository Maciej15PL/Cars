#ifndef UNTITLED_CAR_H
#define UNTITLED_CAR_H

typedef float Weight;
typedef float Liter;

class Car {
public:
    virtual Weight getMaximumPayload() = 0;
    virtual Liter getFuelCapacity() = 0;
    virtual Liter getFuelEfficiency() = 0;

    virtual Weight getPayload() = 0;
    virtual void setPayload(Weight weight) = 0;

    virtual Liter getFuel() = 0;
    virtual void setFuel(Liter amount) = 0;

    virtual bool isLightEnabled() = 0;
    virtual void setLightEnabled(bool enabled) = 0;

    virtual bool isEngineEnabled() = 0;
    virtual void setEngineEnabled(bool enabled) = 0;
};


#endif //UNTITLED_CAR_H
