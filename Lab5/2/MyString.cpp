#include <cstring>
#include "MyString.h"
#include <memory>


CMyString::CMyString() : m_data('\0'), m_length(0)
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
    else if ((m_length < start + length) || (start + length + 1) == start)
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

