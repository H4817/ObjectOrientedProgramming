#pragma once

#include "PersonImpl.h"

class IWorker : public CPersonImpl
{
protected:
    virtual std::string GetProfession() const;
};