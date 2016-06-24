#pragma once

#include "StudentImpl.h"
#include "IStudent.h"

class IAdvancedStudent : public CStudentImpl<IStudent>
{
public:
    virtual void SetSubjectOfDissertation(const std::string &subjectOfDissertation) = 0;

    virtual const std::string &GetSubjectOfDissertation() const = 0;
};