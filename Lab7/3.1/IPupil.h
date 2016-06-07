#pragma once

#include "PersonImpl.h"

class IPupil : public CPersonImpl
{
protected:
    std::string nameOfSchool;
    std::string nameOfClass;
};