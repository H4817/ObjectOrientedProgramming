#pragma once

#include "IPerson.h"

class ITeacher : public IPerson
{
protected:
    std::string nameOfSchoolSubject;
};
