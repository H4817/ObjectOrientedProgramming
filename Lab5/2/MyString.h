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

    CMyString &operator+=(CMyString const &cMyString);

    CMyString &operator=(CMyString const &cMyString);

    char &operator[](size_t position);

    const char &operator[](size_t position) const;

private:
    size_t m_length = 0;
    char *m_data;
};

bool const operator==(CMyString const &cMyString1, CMyString const &cMyString2);

bool const operator!=(CMyString const &cMyString1, CMyString const &cMyString2);

bool const operator>(CMyString const &cMyString1, CMyString const &cMyString2);

bool const operator<(CMyString const &cMyString1, CMyString const &cMyString2);

bool const operator>=(CMyString const &cMyString1, CMyString const &cMyString2);

bool const operator<=(CMyString const &cMyString1, CMyString const &cMyString2);

CMyString const operator+(CMyString const &cMyString1, CMyString const &cMyString2);

CMyString const operator+(const std::string &str1, CMyString const &cMyString2);

CMyString const operator+(const char *ch, CMyString const &cMyString2);

std::ostream &operator<<(std::ostream &outputStream, CMyString const &cMyString);

std::istream &operator>>(std::istream &inputStream, CMyString &cMyString);
