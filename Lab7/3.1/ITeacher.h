#pragma once

#include "PersonImpl.h"

class ITeacher : public CPersonImpl<IPerson>
{
public:
    virtual string GetNameOfSchoolSubject() const;

    virtual void SetNameOfSchoolSubject(const std::string nameOfSchoolSubject);
};
