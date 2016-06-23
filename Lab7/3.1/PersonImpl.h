#pragma once

template<typename Base>
class CPersonImpl : public Base
{
public:

    void SetFirstName(const string firstName)
    {
        CPersonImpl::firstName = firstName;
    }

    void SetSecondName(const string secondName)
    {
        CPersonImpl::secondName = secondName;
    }

    void SetPatronymic(const string patronymic)
    {
        CPersonImpl::patronymic = patronymic;
    }

    void SetAddress(const string address)
    {
        CPersonImpl::address = address;
    }

    virtual std::string GetFirstName() const
    {
        return firstName;
    }

    virtual std::string GetSecondName() const
    {
        return secondName;
    }

    virtual std::string GetPatronymic() const
    {
        return patronymic;
    }

    virtual string GetAddress() const
    {
        return address;
    }

protected:
    std::string firstName;
    std::string secondName;
    std::string patronymic;
    std::string address;
};
//TODO: mixin, interface, abstract class, CRTP