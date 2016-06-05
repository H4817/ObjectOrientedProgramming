#pragma once

#include "IStudent.h"

class IAdvancedStudent : public IStudent
{
protected:
    std::string subjectOfDissertation;
};