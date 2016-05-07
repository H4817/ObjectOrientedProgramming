#include <iostream>
#include "Car.h"
using namespace std;

void Info(const CCar & car)
{
    if(car.IsEngineOn())
    {
        cout << "Engine is on\n";
    }
    else
    {
        cout << "Engine is off\n";
    }
    int direction = car.GetDirection();
    if (direction == 0)
    {
        cout << "Direction is FORWARD\n";
    }
    else if (direction == 1)
    {
        cout << "Direction is BACKWARD\n";
    }
    else
    {
        cout << "Car is stopped\n";
    }
    cout << "Speed: " << car.GetSpeed() << endl;
    cout << "Gear: " << car.GetGear() << endl;
}

bool EngineOn(CCar & car)
{
    return car.TurnOnEngine();
}

bool EngineOff(CCar & car)
{
    return car.TurnOffEngine();
}

bool SetGear(CCar & car, const int & gear)
{
    return car.SetGear(gear);
}

bool SetSpeed(CCar & car, const int & speed)
{
    return car.SetSpeed(speed);
}

void WorkWithUser(CCar & car)
{
    cout << "Type some commands or press q for exit" << endl;
    for (; ;)
    {
        cout << "> ";
        string command;
        int value;
        cin >> command ;
        if (command == "q")
        {
            break;
        }
        if (command == "Info")
        {
            Info(car);
        }
        else if (command == "EngineOn")
        {
            EngineOn(car);
        }
        else if (command == "EngineOff")
        {
            EngineOff(car);
        }
        else if (command == "SetGear")
        {
            cin >> value;
            SetGear(car, value);
        }
        else if (command == "SetSpeed")
        {
            cin >> value;
            SetSpeed(car, value);
        }
    }
}

int main()
{
    CCar car;
    WorkWithUser(car);
    return 0;
}