#pragma once

template<typename Base>
class CPersonImpl : public Base
{
public:
    virtual void SetFirstName(const std::string firstName)
    {
        CPersonImpl::firstName = firstName;
    }

    virtual void SetSecondName(const std::string secondName)
    {
        CPersonImpl::secondName = secondName;
    }

    virtual void SetPatronymic(const std::string patronymic)
    {
        CPersonImpl::patronymic = patronymic;
    }

    virtual void SetAddress(const std::string address)
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

    virtual std::string GetAddress() const
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