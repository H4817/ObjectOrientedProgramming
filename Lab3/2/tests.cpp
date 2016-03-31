#define BOOST_TEST_MODULE MyTestModule

#include <boost/test/included/unit_test.hpp>
#include "Calculator.h"

BOOST_AUTO_TEST_SUITE(CCalculator_tests)

    CCalculator calculator;

    BOOST_AUTO_TEST_CASE(ReadData)
    {
        BOOST_CHECK(calculator.ReadFromFile("inputDoesNotExist.txt"));
        BOOST_CHECK(calculator.ReadFromFile("inputIsEmpty.txt"));
        BOOST_CHECK(calculator.ReadFromFile("input.txt"));
    }
    BOOST_AUTO_TEST_CASE(SeparateInstructions)
    {
        BOOST_CHECK(calculator.SeparateInstructions());
    }

BOOST_AUTO_TEST_SUITE_END()