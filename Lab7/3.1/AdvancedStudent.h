
#pragma once

#include "IAdvancedStudent.h"

class CAdvancedStudent : public CStudentImpl<IAdvancedStudent>
{
public:

    virtual const std::string &GetSubjectOfDissertation() const
    {
        return m_subjectOfDissertation;
    }

    virtual void SetSubjectOfDissertation(const std::string &subjectOfDissertation)
    {
        m_subjectOfDissertation = subjectOfDissertation;
    }

private:
    std::string m_subjectOfDissertation;
};