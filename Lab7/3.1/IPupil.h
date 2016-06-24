#pragma once

#include "IPerson.h"
#include "PersonImpl.h"

class IPupil : public CPersonImpl<IPerson>
{
public:
    virtual std::string GetNameOfSchool() const = 0;

    virtual std::string GetNameOfClass() const = 0;

    virtual void SetNameOfSchool(const std::string nameOfSchool) = 0;

    virtual void SetNameOfClass(const std::string nameOfClass) = 0;
};