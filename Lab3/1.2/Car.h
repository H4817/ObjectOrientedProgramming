#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <limits>


typedef std::pair<int, int> SpeedEdges;

namespace CarDefinitions
{
    static const std::map<int, SpeedEdges> GEAR_EDGES = {
            {-1, {-20, 0}},
            {0, {std::numeric_limits<int>::min(), std::numeric_limits<int>::max()}},
            {1, {0, 30}},
            {2, {20, 50}},
            {3, {30, 60}},
            {4, {40, 90}},
            {5, {50, 150}}
    };
}

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
};


