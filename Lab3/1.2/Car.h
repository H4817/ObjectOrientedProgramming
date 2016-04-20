#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <limits>

using namespace std;

typedef pair <int, int> SpeedEdges;

class CCar
{
public:
    CCar();

    bool TurnOnEngine();

    bool TurnOffEngine();

    bool SetGear(int gear);

    bool SetSpeed(int speed);

    int GetGear();

    int GetSpeed();

    bool IsEngineOn();

    int GetDirection(); //TODO: Const

private:
    // coding style violaton
    enum Gears : int
    {
        FIRST_NEGATIVE = -1,
        ZERO,
        FIRST,
        SECOND,
        THIRD,
        FOURTH,
        FIFTH
    };
    Gears m_gears;
    int m_speed;
    bool m_engineIsOn;
    enum Direction
    {
        FORWARD, BACKWARD, HOLD
    };
    Direction m_direction;
    map <int, SpeedEdges> m_gearEdges;
};


