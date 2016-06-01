#include "Rational.h"
#include <utility>
#include <stdexcept>
#include <stdlib.h>


CRational::CRational(int numerator, int denominator)
        : m_numerator(numerator), m_denominator(denominator)
{
    if (denominator < 0)
    {
        m_numerator = -m_numerator;
        m_denominator = -m_denominator;
    }
    Normalize();
}

int CRational::GetNumerator() const
{
    return m_numerator;
}

int CRational::GetDenominator() const
{
    return m_denominator;
}

void CRational::Normalize()
{
    const int gcd = GCD(abs(m_numerator), m_denominator);
    m_numerator /= gcd;
    m_denominator /= gcd;
}

double CRational::ToDouble()
{
    return static_cast<double>(m_numerator) / static_cast<double>(m_denominator);
}

unsigned GCD(unsigned a, unsigned b)
{
    while (b != 0)
    {
        std::swap(a, b);
        b = b % a;
    }
    return (a != 0) ? a : 1;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 2. Реализовать унарный + и унарный -
//////////////////////////////////////////////////////////////////////////

CRational & CRational::operator+=(CRational const & rational)
{
    *this = *this + rational;
    return *this;
}

CRational & CRational::operator-=(CRational const & rational)
{
    *this = *this - rational;
    return *this;
}

CRational & CRational::operator*=(CRational const & rational)
{
    *this = *this * rational;
    return *this;
}

CRational & CRational::operator/=(CRational const & rational)
{
    *this = *this / rational;
    return *this;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 13. Реализовать оператор вывода рационального числа в выходной поток
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// TODO: 14. Реализовать оператор ввода рационального числа из входного потока
//////////////////////////////////////////////////////////////////////////



