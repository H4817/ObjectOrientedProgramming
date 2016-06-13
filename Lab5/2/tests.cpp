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

    BOOST_AUTO_TEST_CASE(work_with_greater_than_operator)
    {
        CMyString cMyString1("Hello world!!1");

        CMyString cMyString2("Hello friend");

        BOOST_CHECK(cMyString1 > cMyString2);
    }

    BOOST_AUTO_TEST_CASE(work_with_less_than_operator)
    {
        CMyString cMyString1("Hello ");

        CMyString cMyString2("Hello friend");

        BOOST_CHECK(cMyString1 < cMyString2);
    }

    BOOST_AUTO_TEST_CASE(work_with_greater_than_or_equal_to_operator)
    {
        CMyString cMyString1("Hello world!");

        CMyString cMyString2("Hello friend");

        CMyString cMyString3("Hello");

        BOOST_CHECK(cMyString1 >= cMyString2);
        BOOST_CHECK(cMyString2 >= cMyString3);
    }

    BOOST_AUTO_TEST_CASE(work_with_less_than_or_equal_to_operator)
    {
        CMyString cMyString1("Hello world!");

        CMyString cMyString2("Hello friend");

        CMyString cMyString3("Hello");
        BOOST_CHECK(cMyString1 <= cMyString2);
        BOOST_CHECK(cMyString3 <= cMyString2);
    }
    
    BOOST_AUTO_TEST_CASE(work_with_addition_operator)
    {
        CMyString cMyString1("Hello ");
        CMyString cMyString2("w\0rld");
        BOOST_CHECK(cMyString1 + cMyString2 == "Hello w\0rld");
    }

    BOOST_AUTO_TEST_CASE(should_get_correct_substring)
    {
        CMyString cMyString1("test1 test2 test3");
        BOOST_CHECK_NO_THROW(cMyString1.SubString(0, 5));
        BOOST_CHECK(cMyString1.SubString(0, 5) == "test1");
        BOOST_CHECK(cMyString1.SubString(6, 5) == "test2");
        BOOST_CHECK(cMyString1.SubString(12, 5) == "test3");
    }

BOOST_AUTO_TEST_SUITE_END()

