#include <cstring>
#include "MyString.h"

size_t CMyString::GetLength() const
{
    return m_length;
}

CMyString::~CMyString()
{
    if (m_data != '\0')
    {
        delete[]m_data;
    }
}