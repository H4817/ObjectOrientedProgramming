#include "Car.h"

CCar::CCar()
        : m_gears(ZERO), m_speed(0), m_engineIsOn(false), m_direction(HOLD)
{
    /*m_gearEdges = {
            {-1, {0, -20}}, {1, {0, 30}, {2, {20, 50}}, {3, {30, 60}}, {4, {40, 90}}, {5, {50, 150}}}
    };*/
    m_gearEdges.insert(std::make_pair(-1, std::make_pair(-20, 0)));
    m_gearEdges.insert(
            std::make_pair(0, std::make_pair(std::numeric_limits<int>::min(), std::numeric_limits<int>::max())));
    m_gearEdges.insert(std::make_pair(1, std::make_pair(0, 30)));
    m_gearEdges.insert(std::make_pair(2, std::make_pair(20, 50)));
    m_gearEdges.insert(std::make_pair(3, std::make_pair(30, 60)));
    m_gearEdges.insert(std::make_pair(4, std::make_pair(40, 90)));
    m_gearEdges.insert(std::make_pair(5, std::make_pair(50, 150)));
}

bool CCar::TurnOnEngine()
{
    if (m_engineIsOn)
    {
        return false;
    }
    else
    {
        m_engineIsOn = true;
        return true;
    }
}

bool CCar::SetGear(int gear)
{
    if (m_engineIsOn)
    {
        auto pos = m_gearEdges.find(gear);
        if (pos != m_gearEdges.end() && m_speed >= pos->second.first &&
            m_speed <= pos->second.second)
        {
            m_gears = static_cast<Gears>(gear);
            return true;
        }
        else if (gear == 0)
        {
            m_gears = static_cast<Gears>(gear);
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (gear == 0)
        {
            m_gears = static_cast<Gears>(gear);
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool CCar::SetSpeed(int speed)
{
    if (m_engineIsOn && m_gears != 0)
    {
        auto pos = m_gearEdges.find(m_gears);
        if (speed >= pos->second.first && speed <= pos->second.second)
        {
            m_speed = speed;
            if (m_speed > 0)
            {
                m_direction = FORWARD;
            }
            else if (m_speed < 0)
            {
                m_direction = BACKWARD;
            }
            else
            {
                m_direction = HOLD;
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (speed == m_speed)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CCar::TurnOffEngine()
{
    if (m_engineIsOn && m_gears == 0 && m_direction == HOLD)
    {
        m_engineIsOn = false;
        return true;
    }
    else
    {
        return false;
    }
}

int CCar::GetGear()
{
    return m_gears;
}

int CCar::GetSpeed()
{
    return m_speed;
}

bool CCar::IsEngineOn()
{
    return m_engineIsOn;
}

int CCar::GetDirection()
{
    return m_direction;
}

