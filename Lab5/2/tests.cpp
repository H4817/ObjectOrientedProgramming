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
        CMyString cMyString1("Some word");

        CMyString cMyString2("Some word");

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
        CMyString cMyString2("Wow ");

        CMyString cMyString1("Some word");

        BOOST_CHECK(cMyString1 > cMyString2);
    }

    BOOST_AUTO_TEST_CASE(work_with_less_than_operator)
    {
        CMyString cMyString1("Wow ");

        CMyString cMyString2("Some word");

        BOOST_CHECK(cMyString1 < cMyString2);
    }

    BOOST_AUTO_TEST_CASE(work_with_greater_than_or_equal_to_operator)
    {
        CMyString cMyString1("test1 test2.");

        CMyString cMyString2("test1 test0,");

        CMyString cMyString3("test");

        BOOST_CHECK(cMyString1 >= cMyString2);
        BOOST_CHECK(cMyString2 >= cMyString3);
    }

    BOOST_AUTO_TEST_CASE(work_with_less_than_or_equal_to_operator)
    {
        CMyString cMyString1("test1 test2.");

        CMyString cMyString2("test1 test0,");

        CMyString cMyString3("test");
        BOOST_CHECK(cMyString1 <= cMyString2);
        BOOST_CHECK(cMyString3 <= cMyString2);
    }

    BOOST_AUTO_TEST_CASE(work_with_addition_operator)
    {
        CMyString cMyString1("Hello ");
        CMyString cMyString2("w\0rld");
        const char *buddy = "buddy";
        std::string tdd = "TDD";
        BOOST_CHECK(cMyString1 + cMyString2 == "Hello w\0rld");
        BOOST_CHECK(cMyString1 + buddy == "Hello buddy");
        BOOST_CHECK(cMyString1 + tdd == "Hello TDD");
    }

    BOOST_AUTO_TEST_CASE(work_with_basic_assignment)
    {
        CMyString cMyString1("Hello");
        CMyString cMyString2;
        BOOST_CHECK_NO_THROW(cMyString2 = cMyString1);
        BOOST_CHECK_EQUAL(cMyString1.GetStringData(), cMyString2.GetStringData());
//        BOOST_CHECK_NO_THROW(CMyString cMyString3 = cMyString3); //throw expected
    }

    BOOST_AUTO_TEST_CASE(work_with_addition_assignment)
    {
        CMyString cMyString1("Hello ");
        CMyString cMyString2("w\0rld");
        CMyString cMyString3;
        cMyString3 += cMyString1;
        BOOST_CHECK_EQUAL(cMyString1.GetStringData(), cMyString3.GetStringData());
        cMyString3 += cMyString2;
        BOOST_CHECK_EQUAL(cMyString3.GetStringData(), "Hello w\0rld");
    }

    BOOST_AUTO_TEST_CASE(work_with_left_shift_operator)
    {
        std::ostringstream oss;
        oss << CMyString("test");
        BOOST_CHECK_EQUAL(oss.str(), "test");
        oss << CMyString(" word");
        BOOST_CHECK_EQUAL(oss.str(), "test word");
    }

    BOOST_AUTO_TEST_CASE(work_with_right_shift_operator)
    {
        std::istringstream iss("test");
        CMyString cMyString1;
        BOOST_CHECK_NO_THROW(iss >> cMyString1);
        BOOST_CHECK_EQUAL(cMyString1.GetStringData(), "test");
    }

    BOOST_AUTO_TEST_CASE(should_get_correct_substring)
    {
        CMyString cMyString1("test1 test2 test3");
        BOOST_CHECK_NO_THROW(cMyString1.SubString(0, 5));
        BOOST_CHECK(cMyString1.SubString(0, 5) == "test1");
        BOOST_CHECK(cMyString1.SubString(6, 5) == "test2");
        BOOST_CHECK(cMyString1.SubString(12, 5) == "test3");
    }

    BOOST_AUTO_TEST_CASE(work_with_array_subscripting_operator)
    {
        CMyString str("hello");
        BOOST_CHECK_EQUAL(str[0], 'h');
        BOOST_CHECK_EQUAL(str[1], 'e');
        BOOST_CHECK_EQUAL(str[2], 'l');
        BOOST_CHECK_EQUAL(str[3], 'l');
        BOOST_CHECK_EQUAL(str[4], 'o');

        const CMyString str1 = str;
        BOOST_CHECK_EQUAL(str1[0], 'h');
        BOOST_CHECK_EQUAL(str1[1], 'e');
        BOOST_CHECK_EQUAL(str1[2], 'l');
        BOOST_CHECK_EQUAL(str1[3], 'l');
        BOOST_CHECK_EQUAL(str1[4], 'o');
    }

BOOST_AUTO_TEST_SUITE_END()

