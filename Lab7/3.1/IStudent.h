#pragma once

#include "PersonImpl.h"
#include "StudentImpl.h"

class IStudent : public CPersonImpl
{
protected:

    std::string nameOfCollege;
    std::string numberOfStudentsCard;
};