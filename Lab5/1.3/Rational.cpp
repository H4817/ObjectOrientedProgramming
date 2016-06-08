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

std::pair<int, CRational> CRational::ToCompoundFraction()const
{
	int integer = static_cast<int>(ToDouble());
	int numerator = m_numerator - m_denominator * integer;
	return std::make_pair<int, CRational>(std::move(integer), CRational(numerator, m_denominator));
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

double CRational::ToDouble() const
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

CRational const CRational::operator+ () const
{
    return *this;
}

CRational const CRational::operator- ()	const
{
	return CRational(m_numerator * -1, m_denominator);
}

//////////////////////////////////////////////////////////////////////////
// TODO: 14. Реализовать оператор ввода рационального числа из входного потока
//////////////////////////////////////////////////////////////////////////



