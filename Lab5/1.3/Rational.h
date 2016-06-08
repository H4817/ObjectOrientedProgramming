#pragma once

#include <iostream>
#include <sstream>

/*
Класс, моделирующий рациональное число
*/
class CRational final
{
public:
    CRational(int numerator = 0, int denominator = 1);

    // Возвращает числитель
    int GetNumerator() const;

    // Возвращает знаменатель
    int GetDenominator() const;

    double ToDouble() const;

    std::pair<int, CRational> ToCompoundFraction()const;


    //////////////////////////////////////////////////////////////////////////
    // TODO: 14. Реализовать оператор ввода рационального числа из входного потока
    //	std::istream в формате <числитель>/<знаменатель>,
    //	например: 7/15
    //////////////////////////////////////////////////////////////////////////
    CRational const operator+() const;

    CRational const operator-() const;

    CRational &operator+=(CRational const &rational);

    CRational &operator-=(CRational const &rational);

    CRational &operator*=(CRational const &rational);

    CRational &operator/=(CRational const &rational);

private:
    int m_numerator;
    int m_denominator;

    // Нормализует рациональное число
    void Normalize();
};

inline bool operator==(CRational const &rational1, CRational const &rational2)
{
    return ((rational1.GetNumerator() * rational2.GetDenominator()) ==
            (rational2.GetNumerator() * rational1.GetDenominator()));
}

inline bool operator!=(CRational const &rational1, CRational const &rational2)
{
    return ((rational1.GetNumerator() * rational2.GetDenominator()) !=
            (rational2.GetNumerator() * rational1.GetDenominator()));
}

inline bool operator<(CRational const &rational1, CRational const &rational2)
{
    return ((rational1.GetNumerator() * rational2.GetDenominator()) <
            (rational2.GetNumerator() * rational1.GetDenominator()));
}

inline bool operator<=(CRational const &rational1, CRational const &rational2)
{
    return ((rational1.GetNumerator() * rational2.GetDenominator()) <=
            (rational2.GetNumerator() * rational1.GetDenominator()));
}

inline bool operator>=(CRational const &rational1, CRational const &rational2)
{
    return ((rational1.GetNumerator() * rational2.GetDenominator()) >=
            (rational2.GetNumerator() * rational1.GetDenominator()));
}

inline bool operator>(CRational const &rational1, CRational const &rational2)
{
    return ((rational1.GetNumerator() * rational2.GetDenominator()) >
            (rational2.GetNumerator() * rational1.GetDenominator()));
}

inline CRational const operator-(CRational const &rational1, CRational const &rational2)
{
    return (CRational((rational1.GetNumerator() * rational2.GetDenominator()) -
                      (rational2.GetNumerator() * rational1.GetDenominator()),
                      rational1.GetDenominator() * rational2.GetDenominator()));
}

inline CRational const operator+(CRational const &rational1, CRational const &rational2)
{
    return (CRational((rational1.GetNumerator() * rational2.GetDenominator()) +
                      (rational2.GetNumerator() * rational1.GetDenominator()),
                      rational1.GetDenominator() * rational2.GetDenominator()));
}

inline CRational const operator*(CRational const &rational1, CRational const &rational2)
{
    return (CRational(rational1.GetNumerator() * rational2.GetNumerator(),
                      rational1.GetDenominator() * rational2.GetDenominator()));
}

inline CRational const operator/(CRational const &rational1, CRational const &rational2)
{
    return (CRational(rational1.GetNumerator() * rational2.GetDenominator(),
                      rational1.GetDenominator() * rational2.GetNumerator()));
}

inline std::ostream &operator<<(std::ostream &outputStream, CRational const &rational)
{
    return outputStream << rational.GetNumerator() << "/" << rational.GetDenominator();
}

inline std::istream &operator>>(std::istream &inputStream, CRational &rational)
{
    int numerator;
    int denominator;
    if ((inputStream >> numerator) && (inputStream.get() == '/') && (inputStream >> denominator))
    {
        rational = CRational(numerator, denominator);
    }
    return inputStream;
}
//TODO считать числитель, слеш, знаменатель
// Вычисляет наибольший общий знаменатель чисел a и b
unsigned GCD(unsigned a, unsigned b);

