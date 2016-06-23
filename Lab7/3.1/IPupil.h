#pragma once

#include "PersonImpl.h"

class IPupil : public CPersonImpl<IPerson>
{
public:
    virtual string GetNameOfSchool() const;

    virtual string GetNameOfClass() const;

    virtual void SetNameOfSchool(const std::string nameOfSchool);

    virtual void SetNameOfClass(const std::string nameOfClass);
};