#pragma once

#include "IWorker.h"

class CWorker : public CPersonImpl<IWorker>
{
public:
    virtual std::string GetProfession() const
    {
        return m_profession;
    }

    virtual void SetProfession(const std::string profession)
    {
        m_profession = profession;
    }
private:
    std::string m_profession;
};