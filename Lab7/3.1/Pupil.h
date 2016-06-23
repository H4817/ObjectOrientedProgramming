#pragma once

#include "IPupil.h"

class CPupil : public CPersonImpl<IPupil>
{
public:
    virtual std::string GetNameOfSchool() const
    {
        return m_nameOfSchool;
    }

    virtual std::string GetNameOfClass() const
    {
        return m_nameOfClass;
    }
    virtual void SetNameOfSchool(const std::string nameOfSchool)
    {
        m_nameOfSchool = nameOfSchool;
    }

    virtual void SetNameOfClass(const std::string nameOfClass)
    {
        m_nameOfClass = nameOfClass;
    }

private:
    std::string m_nameOfSchool;
    std::string m_nameOfClass;
};