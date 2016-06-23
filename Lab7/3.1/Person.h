#pragma once

#include "IPerson.h"
#include "PersonImpl.h"

class CPerson : public CPersonImpl<IPerson>
{
public:
    CPerson();

/*    CPerson(std::string firstName,
            std::string secondName,
            std::string patronymic,
            std::string address);*/
};


