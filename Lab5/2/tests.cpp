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

    BOOST_AUTO_TEST_CASE(should_initialize_by_value)
    {
        CMyString cMyString1("test");
        BOOST_CHECK(cMyString1.GetLength());
    }

    BOOST_AUTO_TEST_CASE(should_initialize_by_value_and_size)
    {
        CMyString cMyString1("test", 5);
        BOOST_CHECK(cMyString1.GetLength());
    }

    BOOST_AUTO_TEST_CASE(can_get_data_from_string)
    {
        BOOST_CHECK(cMyString.GetStringData()[0] == '\0');
        const char *ch = "test";

        CMyString cMyString1(ch);
        for (int i = 0; i < sizeof(ch) / 2; ++i)
        {
            BOOST_REQUIRE(cMyString1.GetStringData()[i] == ch[i]);
        }
    }

    BOOST_AUTO_TEST_CASE(can_clear_a_string)
    {
        const char *ch = "test";
        CMyString cMyString1(ch);
        BOOST_CHECK_NO_THROW(cMyString1.Clear());
        BOOST_CHECK_NO_THROW(cMyString.Clear());
    }

BOOST_AUTO_TEST_SUITE_END()

