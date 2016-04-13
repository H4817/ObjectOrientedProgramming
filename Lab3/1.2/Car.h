#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <limits>

using namespace std;

class CCar
{
public:
    CCar();

    bool TurnOnEngine();

    bool TurnOffEngine();

    bool SetGear(int gear);

    bool SetSpeed(int speed);

    void GetInfo();

private:
    size_t m_gear;
    size_t m_speed;
    bool m_engineIsOn;
    enum direction {forward, backward, hold};
    direction m_direction;
    map <int, pair<int, int>> m_gearEdges;
};


