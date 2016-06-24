#pragma once

#include "IPerson.h"
#include "PersonImpl.h"

class ITeacher : public CPersonImpl<IPerson>
{
public:
    virtual std::string GetNameOfSchoolSubject() const = 0;

    virtual void SetNameOfSchoolSubject(const std::string nameOfSchoolSubject) = 0;
};
