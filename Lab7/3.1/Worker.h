#pragma once

#include "IWorker.h"

class CWorker : public CPersonImpl<IPerson>
{
public:
    virtual std::string GetProfession() const
    {
        return profession;
    }
private:
    std::string profession;
};