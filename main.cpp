#include "racingCar.h"

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<Car *> cars;

    Car *car1 = new Car("Hyundai", "Veloster N TCR");
    car1->maxCarSpeed = 155;
    cars.push_back(car1);
    Car *car2 = new Car("McLaren", "720S GT3");
    car2->maxCarSpeed = 212;
    cars.push_back(car2);
    Car *car3 = new Car("Toyoto", "Supra GT4");
    car3->maxCarSpeed = 163;
    cars.push_back(car3);
    Car *car4 = new Car("Mercedes", "AMG GT4");
    car4->maxCarSpeed = 168;
    cars.push_back(car4);

    // display car information for each car
    for (int carNum = 0; carNum < cars.size(); carNum++)
    {
        cout << "Car " << (carNum + 1) << " details:" << endl;
        cout << "Brand: " << cars[carNum]->brand << endl
             << "Model: " << cars[carNum]->model << endl
             << "Top speed: " << cars[carNum]->maxCarSpeed << " mph" << endl
             << endl;

        // start all the cars
        cars[carNum]->startEngine();
    }

    cout << "Launching all the cars! Gear set to 1!" << endl;

    int racingTracks = 5;

    for (int track = 1; track <= racingTracks; track++)
    {
        cout << endl
             << "------------- Track " << track << endl;

        // accelerate the car
        for (int carNum = 0; carNum < cars.size(); carNum++)
        {
            if (track == 2)
            {
                cars[carNum]->shift(5);
                cars[carNum]->pedal();
                cars[carNum]->pedal();
            }
            cout << cars[carNum]->model << " accelerating. ";

            // car pedal's 3 times to reach top speed
            int pedals = 1;
            while (pedals <= 3)
            {
                cars[carNum]->pedal();
                pedals += 1;
            }
            cout << "Car Speed: " << cars[carNum]->getSpeed() << " mph Gear: " << cars[carNum]->getGear() << endl;

            // all the cars change their gear to 5 by the time they reach track 2
        }

        // randomly brake a car, shift the gear and accelerate
        int randomCar = 1;
        while (track >= 2 && randomCar <= 2)
        {
            int randomIndex = rand() % 4;
            cars[randomIndex]->brake();
            cars[randomIndex]->shift(8);
            cars[randomIndex]->pedal();
            cout << cars[randomIndex]->model << " is braking. Shifted gear to " << cars[randomIndex]->getGear() << " Car speed: " << cars[randomIndex]->getSpeed() << "mph" << endl;
            randomCar += 1;
        }
    }

    for (int carNum = 0; carNum < cars.size(); carNum++)
    {
        delete cars[carNum];
    }

    return 0;
}