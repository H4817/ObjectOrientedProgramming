#pragma once

#include "IPerson.h"
#include "PersonImpl.h"

class IWorker : public CPersonImpl<IPerson>
{
public:
    virtual std::string GetProfession() const = 0;

    virtual void SetProfession(const std::string profession) = 0;
};