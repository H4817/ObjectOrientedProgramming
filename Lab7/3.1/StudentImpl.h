#pragma once

#include "IStudent.h"
#include "PersonImpl.h"

template <typename Base>
class CStudentImpl : public CPersonImpl<Base>
{
public:
    const std::string &GetNameOfCollege() const
    {
        return m_nameOfCollege;
    }

    void SetNameOfCollege(const std::string &nameOfCollege)
    {
        m_nameOfCollege = nameOfCollege;
    }

    const std::string &GetNumberOfStudentsCard() const
    {
        return m_numberOfStudentsCard;
    }

    void SetNumberOfStudentsCard(const std::string &numberOfStudentsCard)
    {
        m_numberOfStudentsCard = numberOfStudentsCard;
    }

private:
    std::string m_nameOfCollege;
    std::string m_numberOfStudentsCard;
};