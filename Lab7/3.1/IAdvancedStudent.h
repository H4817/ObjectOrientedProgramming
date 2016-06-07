#pragma once

#include "StudentImpl.h"

class IAdvancedStudent : public CStudentImpl
{
protected:
    std::string subjectOfDissertation;
};