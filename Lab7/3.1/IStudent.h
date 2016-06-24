#pragma once

#include "IPerson.h"
#include "PersonImpl.h"

class IStudent : public CPersonImpl<IPerson>
{
public:
    virtual const std::string &GetNameOfCollege() const = 0;
    virtual void SetNameOfCollege(const std::string &nameOfCollege) = 0;
    virtual const std::string &GetNumberOfStudentsCard() const = 0;
    virtual void SetNumberOfStudentsCard(const std::string &numberOfStudentsCard) = 0;
};