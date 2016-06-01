#define BOOST_TEST_MODULE MyTestModule

#include <boost/test/included/unit_test.hpp>

#include "Rational.h"

BOOST_AUTO_TEST_CASE(Test_Greates_Common_Denominator)
{
    BOOST_CHECK_EQUAL(GCD(2, 6), 2u);
    BOOST_CHECK_EQUAL(GCD(3, 2), 1u);
    BOOST_CHECK_EQUAL(GCD(12, 8), 4u);
    BOOST_CHECK_EQUAL(GCD(8, 12), 4u);
    BOOST_CHECK_EQUAL(GCD(0, 2), 2u);
    BOOST_CHECK_EQUAL(GCD(2, 0), 2u);
    BOOST_CHECK_EQUAL(GCD(0, 0), 1u);
}

/*
  Рациональное число:
	равно нулю по умолчанию (0/1)
	может быть созданно из целого в формате (n / 1)
	может быть задано с указанием числителя и знаменателя
	хранится в нормализованном виде
	*/

void VerifyRational(const CRational &r, int expectedNumerator, int expectedDenominator)
{
    BOOST_CHECK_EQUAL(r.GetNumerator(), expectedNumerator);
    BOOST_CHECK_EQUAL(r.GetDenominator(), expectedDenominator);
}

BOOST_AUTO_TEST_SUITE(Rational_number)

    BOOST_AUTO_TEST_CASE(is_0_by_default)
    {
        VerifyRational(CRational(), 0, 1);
    }

    BOOST_AUTO_TEST_CASE(can_be_constructed_from_integer)
    {
        VerifyRational(CRational(10), 10, 1);
        VerifyRational(CRational(-10), -10, 1);
        VerifyRational(CRational(0), 0, 1);
    }

    BOOST_AUTO_TEST_CASE(can_be_constructed_with_numerator_and_denominator)
    {
        VerifyRational(CRational(5, 2), 5, 2);
        VerifyRational(CRational(-5, 2), -5, 2);
        VerifyRational(CRational(5, -2), -5, 2);
        VerifyRational(CRational(-5, -2), 5, 2);
    }

    BOOST_AUTO_TEST_CASE(is_normalized_after_construction)
    {
        VerifyRational(CRational(6, 8), 3, 4);
        VerifyRational(CRational(6, -8), -3, 4);
        VerifyRational(CRational(-6, 8), -3, 4);
        VerifyRational(CRational(-6, -8), 3, 4);
        VerifyRational(CRational(-10, 20), -1, 2);
    }

    BOOST_AUTO_TEST_CASE(work_with_unary_minus)
    {
        VerifyRational(-CRational(1, 3), -1, 3);
    }

    BOOST_AUTO_TEST_CASE(work_with_unary_plus)
    {
        VerifyRational(+CRational(-1, 3), 1, 3);
    }

    BOOST_AUTO_TEST_CASE(work_with_the_binary_plus)
    {
        VerifyRational(CRational(1, 2) + CRational(1, 6), 2, 3);
        VerifyRational(CRational(1, 2) + CRational(1), 3, 2);
        VerifyRational(CRational(1) + CRational(1, 2), 3, 2);
        VerifyRational(CRational(1, 2) + 1, 3, 2);
        VerifyRational(1 + CRational(1, 2), 3, 2);
    }

    BOOST_AUTO_TEST_CASE(work_with_the_binary_minus)
    {
        VerifyRational(CRational(1, 2) - CRational(1, 6), 1, 3);
        VerifyRational(CRational(1, 2) - CRational(1), -1, 2);
        VerifyRational(CRational(1) - CRational(1, 2), 1, 2);
        VerifyRational(CRational(1, 2) - 1, -1, 2);
        VerifyRational(1 - CRational(1, 2), 1, 2);
    }

    BOOST_AUTO_TEST_CASE(work_with_addition_assignment)
    {
        VerifyRational(CRational(1, 2) += CRational(1, 6), 2, 3);
        VerifyRational(CRational(1, 2) += 1, 3, 2);
    }

    BOOST_AUTO_TEST_CASE(work_with_subtraction_assignment)
    {
        VerifyRational(CRational(1, 2) -= CRational(1, 6), 1, 3);
        VerifyRational(CRational(1, 2) -= 1, -1, 2);
    }

    BOOST_AUTO_TEST_CASE(work_with_the_simple_multiplication)
    {
        VerifyRational(CRational(1, 3) * CRational(1, 3), 1, 9);
        VerifyRational(CRational(1, 2) * -3, -3, 2);
    }

    BOOST_AUTO_TEST_CASE(work_with_the_simple_division)
    {
        VerifyRational(CRational(1, 3) / CRational(3, 4), 4, 9);
        VerifyRational(CRational(1, 2) / 5, 1, 10);
        VerifyRational(7 / CRational(2, 3), 21, 2);
    }

    BOOST_AUTO_TEST_CASE(work_with_multiplication_assignment)
    {
        VerifyRational(CRational(1, 2) *= CRational(2, 3), 1, 3);
        VerifyRational(CRational(1, 2) *= 3, 3, 2);
    }

    BOOST_AUTO_TEST_CASE(work_with_to_double)
    {
        CRational cRational(1, 3);
        BOOST_CHECK_CLOSE(cRational.ToDouble(), 0.333333, 1e-1);
    }

    BOOST_AUTO_TEST_CASE(work_with_division_assignment)
    {
        VerifyRational(CRational(1, 2) /= CRational(2, 3), 3, 4);
        VerifyRational(CRational(1, 2) /= 3, 1, 6);
    }

    BOOST_AUTO_TEST_CASE(work_with_equal_to_operator)
    {
        BOOST_CHECK(CRational(1, 2) == CRational(1, 2));
        BOOST_CHECK(CRational(4, 1) == 4);
        BOOST_CHECK(3 == CRational(3, 1));
    }

    BOOST_AUTO_TEST_CASE(work_with_not_equal_to_operator)
    {
        BOOST_CHECK(CRational(1, 2) != CRational(2, 3));
        BOOST_CHECK(CRational(1, 2) != 7);
        BOOST_CHECK(3 != CRational(2, 3));
    }

    BOOST_AUTO_TEST_CASE(compare)
    {
        BOOST_CHECK(CRational(1, 2) >= CRational(1, 3));
        BOOST_CHECK(!(CRational(1, 2) <= CRational(1, 3)));
        BOOST_CHECK(CRational(3, 1) > CRational(2));
        BOOST_CHECK(CRational(1, 2) < CRational(7));
        BOOST_CHECK(CRational(3) <= CRational(7, 2));
        BOOST_CHECK(!(CRational(1, 2) >= CRational(8, 2)));
    }
//////////////////////////////////////////////////////////////////////////
// TODO: 13. Реализовать оператор вывода рационального числа в выходной поток
//	std::ostream в формате <числитель>/<знаменатель>,
//	например: 7/15
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// TODO: 14. Реализовать оператор ввода рационального числа из входного потока
//	std::istream в формате <числитель>/<знаменатель>,
//	например: 7/15
//////////////////////////////////////////////////////////////////////////


BOOST_AUTO_TEST_SUITE_END()
