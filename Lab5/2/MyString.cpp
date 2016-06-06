#include <cstring>
#include "MyString.h"

size_t CMyString::GetLength() const
{
    return m_length;
}

CMyString::CMyString() : m_data('\0'), m_length(0)
{ }

CMyString::CMyString(const char *pString) : m_length(strlen(pString)), m_data(new char[m_length + 1])
{
    memcpy(m_data, pString, m_length);
    m_data[m_length] = '\0';
}

CMyString const CMyString::SubString(size_t start, size_t length) const
{
    if (start >= m_length || start > length)
    {
        throw std::out_of_range("Out of range");
    }
    else if ((!m_data) || (start == length))
    {
        return '\0';
    }
    else if (length > m_length)
    {
        length = m_length;
    }
    return CMyString(&m_data[length], length);
}

const char *CMyString::GetStringData() const
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
        m_data = '\0';
    }
    m_length = 0;
}

CMyString::~CMyString()
{
    Clear();
}
