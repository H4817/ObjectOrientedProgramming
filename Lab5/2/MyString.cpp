#include <cstring>
#include "MyString.h"

size_t CMyString::GetLength() const
{
    return m_length;
}

CMyString::CMyString() : m_data(nullptr), m_length(0)
{ }

CMyString::CMyString(const char *pString) : m_length(strlen(pString)), m_data(new char[m_length + 1])
{
    memcpy(m_data, pString, m_length);
    m_data[m_length] = '\0';
}

const char* CMyString::GetStringData() const
{
    if (!m_data)
    {
        return "\0";
    }
    return m_data;
}

CMyString::CMyString(const char *pString, size_t length) : m_length(length), m_data(new char[m_length + 1])
{
    memcpy(m_data, pString, m_length);
    m_data[m_length] = '\0';
}

void CMyString::Clear()
{
    if (m_data != '\0')
    {
        delete[]m_data;
    }
    m_length = 0;
}

CMyString::~CMyString()
{
    Clear();
}
