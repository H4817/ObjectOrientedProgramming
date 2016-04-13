#include <iostream>
#include "Car.h"

using namespace std;


void Info(CCar & car)
{
    car.GetInfo();
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
    string str;
    cout << "Type some commands or press q for exit: " << endl;
    while (str != "q")
    {
        cout << "> " << endl;
        cin >> str;
        if (str == "Info")
        {
            Info(car);
        }
        else if (str == "EngineOn")
        {
            EngineOn(car);
        }
        else if (str == "EngineOff")
        {
            EngineOff(car);
        }
        else if (str.substr(0, 7) == "SetGear")
        {
            SetGear(car, stoi(str.substr(7, str.length() - 7)));
        }
        else if (str.substr(0, 8) == "SetSpeed")
        {
            SetGear(car, stoi(str.substr(8, str.length() - 8)));
        }

    }
}

int main()
{
    CCar car;
    WorkWithUser(car);
    return 0;
}