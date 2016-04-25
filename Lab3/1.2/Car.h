#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <limits>


typedef std::pair<int, int> SpeedEdges;

class CCar
{
public:
    CCar();

    bool TurnOnEngine();

    bool TurnOffEngine();

    bool SetGear(int gear);

    bool SetSpeed(int speed);

    int GetGear() const;

    int GetSpeed() const;

    bool IsEngineOn() const;

    int GetDirection() const;

private:
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
    std::map<int, SpeedEdges> m_gearEdges;
};
