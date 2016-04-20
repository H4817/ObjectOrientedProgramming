#define BOOST_TEST_MODULE MyTestModule

#include <boost/test/included/unit_test.hpp>
#include "Calculator.h"

static const char C_INPUT_1[] = R"***(
var b
var a
var a
let a=4.12314124125125125152
let b=a
fn outx=a+b
fn outx1=outx+outx
fn outx2=outx1*outx
fn outx3=outx2/outx1
fn outx4=outx3-b
print c
printvars
printfn
)***";

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