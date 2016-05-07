#include "Car.h"

using namespace std;

CCar::CCar()
        : m_gears(ZERO), m_speed(0), m_engineIsOn(false), m_direction(HOLD)
{

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
        auto pos = CarDefinitions::GEAR_EDGES.find(gear);
        if (pos != CarDefinitions::GEAR_EDGES.end() && m_speed >= pos->second.first &&
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
        auto pos = CarDefinitions::GEAR_EDGES.find(m_gears);
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

int CCar::GetGear() const
{
    return m_gears;
}

int CCar::GetSpeed() const
{
    return m_speed;
}

bool CCar::IsEngineOn() const
{
    return m_engineIsOn;
}

int CCar::GetDirection() const
{
    return m_direction;
}

