#pragma once

#include "PersonImpl.h"

class ITeacher : public CPersonImpl
{
protected:
    std::string nameOfSchoolSubject;
};
