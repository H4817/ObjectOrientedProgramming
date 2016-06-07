#pragma once

template <typename Base>
class CPersonImpl : public Base
{
protected:
    std::string firstName;
    std::string secondName;
    std::string patronymic;
    std::string address;
};