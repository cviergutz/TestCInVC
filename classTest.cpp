#include <iostream>
using namespace std;

class Vehicle
{
protected:
    int nrOfWheels;

public:
    Vehicle();
    Vehicle(int wheels);
    ~Vehicle();
};

Vehicle::Vehicle()
{
}

Vehicle::Vehicle(int wheels) : nrOfWheels(wheels)
{
}

Vehicle::~Vehicle()
{
}

class Car : public Vehicle
{
protected:
    int horsePower;

public:
    Car();
    Car(int wheels);
    ~Car();
};

Car::Car()
{
}

Car::Car(int wheels)
{
    nrOfWheels = wheels;
}

Car::~Car()
{
}

int main(int argc, char *argv[])
{
    for (size_t i = 1; i < argc; i++)
    {
        cout << argv[i] << endl;
    }

    Vehicle *fastCar = new Car(4);
}