#include <iostream>
#include <algorithm>

class CMyString
{
public:
    CMyString();

    CMyString(const char *pString);

    CMyString(const char *pString, size_t length);

    CMyString(const CMyString &other);

    CMyString(const std::string &stlString);

    CMyString(CMyString &&other);

    ~CMyString();

    size_t GetLength() const;

    const char *GetStringData() const;

    const CMyString SubString(size_t start, size_t length = SIZE_MAX) const;

    void Clear();

private:
    size_t m_length = 0;
    char *m_data;

};

inline bool const operator==(CMyString const &cMyString1, CMyString const &cMyString2)
{
    if (cMyString1.GetLength() != cMyString2.GetLength())
    {
        return false;
    }
    return memcmp(cMyString1.GetStringData(), cMyString2.GetStringData(), cMyString1.GetLength()) == 0;
}

inline bool const operator!=(CMyString const &cMyString1, CMyString const &cMyString2)
{
    if (cMyString1.GetLength() != cMyString2.GetLength())
    {
        return true;
    }
    return memcmp(cMyString1.GetStringData(), cMyString2.GetStringData(), cMyString1.GetLength()) != 0;
}

inline bool const operator>(CMyString const &cMyString1, CMyString const &cMyString2)
{
    return cMyString1.GetLength() > cMyString2.GetLength();
}

inline bool const operator<(CMyString const &cMyString1, CMyString const &cMyString2)
{
    return cMyString1.GetLength() < cMyString2.GetLength();
}

inline bool const operator>=(CMyString const &cMyString1, CMyString const &cMyString2)
{
    return cMyString1.GetLength() >= cMyString2.GetLength();
}

inline bool const operator<=(CMyString const &cMyString1, CMyString const &cMyString2)
{
    return cMyString1.GetLength() <= cMyString2.GetLength();
}

inline CMyString const operator+(CMyString const &cMyString1, CMyString const &cMyString2)
{
    std::string str1(cMyString1.GetStringData());
    std::string str2(cMyString2.GetStringData());
    return CMyString((str1 + str2).c_str(), cMyString1.GetLength() + cMyString2.GetLength());
}
