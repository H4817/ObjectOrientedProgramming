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
        BOOST_CHECK(cMyString1.GetStringData()[0] == 't');
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
        for (int i = 0; i < strlen(ch); ++i)
        {
            BOOST_REQUIRE(cMyString1.GetStringData()[i] == ch[i]);
        }
    }

    BOOST_AUTO_TEST_CASE(can_clear_a_hollow_string)
    {
        BOOST_CHECK_NO_THROW(cMyString.Clear());
    }

    BOOST_AUTO_TEST_CASE(work_with_equal_to_operator)
    {
        CMyString cMyString1("Hello world");

        CMyString cMyString2("Hello world");

        BOOST_CHECK(cMyString1 == cMyString2);
    }

    BOOST_AUTO_TEST_CASE(work_with_not_equal_to_operator)
    {
        CMyString cMyString1("Hello world!");

        CMyString cMyString2("Hello friend");

        BOOST_CHECK(cMyString1 != cMyString2);
    }

    BOOST_AUTO_TEST_CASE(work_with_Greater_than_operator)
    {
        CMyString cMyString1("Hello world!!1");

        CMyString cMyString2("Hello friend");

        BOOST_CHECK(cMyString1 > cMyString2);
    }

    BOOST_AUTO_TEST_CASE(should_get_correct_substr)
    {
        const char *ch = "Hello world";
        CMyString cMyString1(ch);
        CMyString cMyString2("world");
        BOOST_CHECK(!(cMyString1.SubString(2, 3) == cMyString2.GetStringData()));
    }


BOOST_AUTO_TEST_SUITE_END()

