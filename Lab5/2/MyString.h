#include <iostream>
#include <algorithm>

class CMyString
{
public:
    CMyString();

    CMyString(const char *pString);

    CMyString(const char *pString, size_t length);

    CMyString(CMyString const &other);

    CMyString(CMyString &&other);

    CMyString(std::string const &stlString);

    ~CMyString();

    size_t GetLength() const;

    const char *GetStringData() const;

    CMyString const SubString(size_t start, size_t length = SIZE_MAX) const;

    void Clear();

private:
    char *m_data;
    size_t m_length = 0;
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
