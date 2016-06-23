#pragma once

#include "IPerson.h"
#include "PersonImpl.h"

class IWorker : public CPersonImpl<IPerson>
{
public:
    virtual std::string GetProfession() const;

    virtual void SetProfession(const std::string profession);
};