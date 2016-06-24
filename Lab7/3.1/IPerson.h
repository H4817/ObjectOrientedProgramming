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
    virtual void SetFirstName(const std::string firstName) = 0;
    virtual void SetSecondName(const std::string secondName) = 0;
    virtual void SetPatronymic(const std::string patronymic) = 0;
    virtual void SetAddress(const std::string address) = 0;
};
