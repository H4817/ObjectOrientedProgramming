#define BOOST_TEST_MODULE MyTestModule

#include <boost/test/included/unit_test.hpp>
#include "MyString.h"

struct MyString
{
    CMyString cMyString;
};

BOOST_FIXTURE_TEST_SUITE(string_test, MyString)
    BOOST_AUTO_TEST_CASE(should_get_zero_length)
    {
        BOOST_CHECK(!cMyString.GetLength());
    }
BOOST_AUTO_TEST_SUITE_END()

