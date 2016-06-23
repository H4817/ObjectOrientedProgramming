#pragma once

#include "ITeacher.h"

class CTeacher : public CPersonImpl<ITeacher>
{
public:
    virtual string GetNameOfSchoolSubject() const
    {
        return m_nameOfSchoolSubject;
    }

    virtual void SetNameOfSchoolSubject(const std::string nameOfSchoolSubject)
    {
        m_nameOfSchoolSubject = nameOfSchoolSubject;
    }
private:
    std::string m_nameOfSchoolSubject;
};