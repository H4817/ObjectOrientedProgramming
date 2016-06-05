#pragma once

#include "IPerson.h"

class IPupil : public IPerson
{
protected:
    std::string nameOfSchool;
    std::string nameOfClass;
};