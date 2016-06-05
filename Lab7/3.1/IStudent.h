#pragma once

#include "IPerson.h"

class IStudent : public IPerson
{
protected:
    std::string nameOfCollege;
    std::string numberOfStudentsCard;
};