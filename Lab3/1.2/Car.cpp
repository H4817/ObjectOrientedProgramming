#include "Car.h"

CCar::CCar() : m_gear(0), m_speed(0), m_engineIsOn(false), m_direction(hold)
{
    m_gearEdges.insert(std::make_pair(-1, std::make_pair(0, -20)));
    m_gearEdges.insert(std::make_pair(0, std::make_pair(std::numeric_limits<int>::min(), std::numeric_limits<int>::max())));
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
        if (pos != m_gearEdges.end() && m_speed >= pos->second.first && m_speed <= pos->second.second ) //&& m_direction != hold
        {
            m_gear = static_cast<size_t>(gear);
            return true;
        }
        else if (gear == 0)
        {
            m_gear = static_cast<size_t>(gear);
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
            m_gear = static_cast<size_t>(gear);
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
    if (m_engineIsOn && m_gear != 0)
    {
        auto pos = m_gearEdges.find(static_cast<int>(m_gear));
        if (speed >= pos->second.first && speed <= pos->second.second) //&& m_direction != hold
        {
            m_speed = static_cast<size_t>(speed);
            if (m_speed > 0)
            {
                m_direction = forward;
            }
            else if (m_speed < 0)
            {
                m_direction = backward;
            }
            else
            {
                m_direction = hold;
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool CCar::TurnOffEngine()
{
    if (m_engineIsOn && m_gear == 0 && m_direction == hold)
    {
        m_engineIsOn = false;
        return true;
    }
    else
    {
        return false;
    }
}

void CCar::GetInfo()
{
    cout << m_engineIsOn << " " << m_direction << " " << m_speed << " " << m_gear << endl;
}
