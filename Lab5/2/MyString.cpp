#include <cstring>
#include "MyString.h"
#include <memory>


CMyString::CMyString() : m_data(nullptr), m_length(0)
{ }

CMyString::CMyString(const char *pString) : CMyString(pString, strlen(pString))
{ }

CMyString::CMyString(const char *pString, size_t length) : m_length(length), m_data(new char[m_length + 1])
{
    m_data[m_length] = '\0';
    memcpy(m_data, pString, m_length);
}

CMyString::CMyString(const CMyString &other) : CMyString(other.GetStringData(), other.GetLength())
{ }

CMyString::CMyString(const std::string &stlString)
        : CMyString(stlString.c_str(), stlString.size())
{ }

CMyString::CMyString(CMyString &&other)
        : m_data(other.m_data), m_length(other.m_length)
{
    other.Clear();
}

CMyString::~CMyString()
{
    delete[]m_data;
}

size_t CMyString::GetLength() const
{
    return m_length;
}

const char *CMyString::GetStringData() const
{
    if (!m_data)
    {
        return "\0";
    }
    return m_data;
}

const CMyString CMyString::SubString(size_t start, size_t length) const
{
    if (start > m_length)
    {
        throw std::out_of_range("Start pos should be less than string length");
    }
    if (start == m_length)
    {
        return CMyString();
    }
    if ((m_length < start + length) || length + 1 == 0)
    {
        length = m_length - start;
    }
    return CMyString(GetStringData() + start, length);
}

void CMyString::Clear()
{
    delete[]m_data;
    m_length = 0;
}

CMyString &CMyString::operator=(CMyString const &cMyString)
{
    if (*this != cMyString)
    {
        auto tmp = cMyString;
        std::swap(m_data, tmp.m_data);
        std::swap(m_length, tmp.m_length);
    }
    return *this;
}

bool const operator==(CMyString const &cMyString1, CMyString const &cMyString2)
{
    if (cMyString1.GetLength() != cMyString2.GetLength())
    {
        return false;
    }
    return memcmp(cMyString1.GetStringData(), cMyString2.GetStringData(), cMyString1.GetLength()) == 0;
}

bool const operator!=(CMyString const &cMyString1, CMyString const &cMyString2)
{
    if (cMyString1.GetLength() != cMyString2.GetLength())
    {
        return true;
    }
    return memcmp(cMyString1.GetStringData(), cMyString2.GetStringData(), cMyString1.GetLength()) != 0;
}

bool const operator>(CMyString const &cMyString1, CMyString const &cMyString2)
{
    return cMyString1.GetLength() > cMyString2.GetLength();
}

bool const operator<(CMyString const &cMyString1, CMyString const &cMyString2)
{
    return cMyString1.GetLength() < cMyString2.GetLength();
}

bool const operator>=(CMyString const &cMyString1, CMyString const &cMyString2)
{
    return cMyString1.GetLength() >= cMyString2.GetLength();
}

bool const operator<=(CMyString const &cMyString1, CMyString const &cMyString2)
{
    return cMyString1.GetLength() <= cMyString2.GetLength();
}

CMyString const operator+(CMyString const &cMyString1, CMyString const &cMyString2)
{
    std::string str1(cMyString1.GetStringData());
    std::string str2(cMyString2.GetStringData());
    return CMyString((str1 + str2).c_str(), cMyString1.GetLength() + cMyString2.GetLength());
}

CMyString const operator+(const std::string &str1, CMyString const &cMyString2)
{
    std::string str2(cMyString2.GetStringData());
    return CMyString((str1 + str2).c_str(), str1.length() + cMyString2.GetLength());
}

CMyString const operator+(const char *ch, CMyString const &cMyString2)
{
    std::string str1(ch);
    std::string str2(cMyString2.GetStringData());
    return CMyString((str1 + str2).c_str(), strlen(ch) + cMyString2.GetLength());
}

std::ostream &operator<<(std::ostream &outputStream, CMyString const &cMyString)
{
    return outputStream << cMyString.GetStringData();
}

std::istream &operator>>(std::istream &inputStream, CMyString &cMyString)
{
    std::string tmp;
    inputStream >> tmp;
    cMyString = tmp;
    return inputStream;
}

CMyString &CMyString::operator+=(CMyString const &cMyString)
{
    *this = *this + cMyString;
    return *this;
}

char &CMyString::operator[](size_t position)
{
    if (position <= m_length)
        return m_data[position];
    else
        throw std::out_of_range("out of range");
}

const char &CMyString::operator[](size_t position) const
{
    if (position <= m_length)
        return m_data[position];
    else
        throw std::out_of_range("out of range");
}
