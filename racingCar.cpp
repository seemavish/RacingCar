// Reusing car simulation code for racing cars

#include "racingCar.h"

#include <iostream>

using namespace std;

// get gear from Vehicle
int Vehicle::getGear()
{
    return gear;
}

// get speed from Vehicle
double Vehicle::getSpeed() const
{
    return speed;
}

// set default speed to 0, gear to 0, and assign brand name to brand variable
Vehicle::Vehicle(string brand) : speed(0), gear(0), brand(brand) {}

// destructor to free up space
Vehicle::~Vehicle() {}

// accelerate the car
// there is a speed limit for every gear which is tracked using maxGearSpeed, which is initialized to 0
void Car::pedal()
{
    int maxGearSpeed = 0;

    switch (gear)
    {
    case 1:
        maxGearSpeed = 10;
        break;
    case 2:
        maxGearSpeed = 20;
        break;
    case 3:
        maxGearSpeed = 30;
        break;
    case 4:
        maxGearSpeed = 40;
        break;
    case 5:
        maxGearSpeed = maxCarSpeed;
        break;
    default:
        maxGearSpeed = 0;
    }

    // make sure we are not exceeding the gear speed limit
    if (speed < maxGearSpeed)
    {
        speed += 10;
        cout << "Accelerate --> Car speed : " << getSpeed() << " Gear : " << getGear() << endl;
    }
    else
    {
        throw "Tring to accelerate! Already at its maximum speed.";
    }
}

// store car brand and model names in brand and model variables, respectively
Car::Car(string brand, string model) : Vehicle(brand), model(model) {}

// deallocate car constructors to free up memory space
Car::~Car() {}

// press brake to slow down the car
void Car::brake()
{
    // car is moving whem spead is greater than 0, else it stops
    if (speed > 0)
    {
        speed -= 10;
        cout << "Brake --> Car speed : " << getSpeed() << " Gear : " << getGear() << endl;
    }
    else
    {
        speed = 0;
        cout << "Trying to brake! The car has stopped" << endl;
    }
}

// start the engine and let's with gear 1
void Car::startEngine(){
    gear = 1;
}

// change the gear when needed
// gear can be shifted between 1 and 5
void Car::shift(int newGear)
{
    if (newGear >= 1 && newGear <= 5)
    {
        gear = newGear;

        cout << "Gear has shifted to " << gear << endl;
    }
    else
    {
        cout << "Invalid gear. Enter between 1 and 5." << endl;
    }
}
