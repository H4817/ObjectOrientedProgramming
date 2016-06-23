#pragma once

#include <iostream>

class IPerson
{
public:
    virtual ~IPerson() = default;
    virtual std::string GetFirstName() const = 0;
    virtual std::string GetSecondName() const = 0;
    virtual std::string GetPatronymic() const = 0;
    virtual std::string GetAddress() const = 0;
};
