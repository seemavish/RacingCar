#include "racingCar.h"

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const int totalCars = 4;
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
    for (int carNum = 0; carNum < totalCars; carNum++)
    {
        cout << "Car " << (carNum + 1) << " details:" << endl;
        cout << "Brand: " << cars[carNum]->brand << endl
             << "Model: " << cars[carNum]->model << endl
             << "Top speed: " << cars[carNum]->maxCarSpeed << " mph" << endl
             << endl;

        // start all the cars
        cars[carNum]->startEngine();
    }

    cout << "All car engines started with gear set to 1!" << endl;

    int racingTracks = 5;

    for (int track = 1; track <= racingTracks; track++)
    {
        cout << "Track " << track << endl;

        // accelerate the car
        for (int carNum = 0; carNum < totalCars; carNum++)
        {
            cars[carNum]->pedal();
            cars[carNum]->pedal();

            // all the cars change their gear to 5 by the time they reach track 2
            if(track==2){
                cars[carNum]->shift(5);
            }
        }

        // randomly brake a car
        int b = rand() % 4;
        cars[b]->brake();
    }

    for (int carNum = 0; carNum < totalCars; carNum++)
    {
        delete cars[carNum];
    }

    return 0;
}