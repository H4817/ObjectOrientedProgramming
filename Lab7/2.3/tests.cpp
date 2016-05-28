#define BOOST_TEST_MODULE MyTestModule

#include <boost/test/included/unit_test.hpp>
#include "MyList.h"

BOOST_AUTO_TEST_SUITE(initialization_tests)
    BOOST_AUTO_TEST_CASE(should_being_initialized_by_default_value_type)
    {
        BOOST_CHECK_NO_THROW(CMyList <int> cMyList1);
    }

    BOOST_AUTO_TEST_CASE(should_push_numbers_and_strings)
    {
        CMyList <int> cMyList1;
        BOOST_CHECK_NO_THROW(cMyList1.Push(3));
        BOOST_CHECK_NO_THROW(cMyList1.Push(1.f));
        BOOST_CHECK_NO_THROW(cMyList1.Push());
        CMyList <std::string> cMyList2;
        BOOST_CHECK_NO_THROW(cMyList2.Push("123"));
        BOOST_CHECK_NO_THROW(cMyList2.Push("test"));
        BOOST_CHECK_NO_THROW(cMyList2.Push());
    }

BOOST_AUTO_TEST_SUITE_END()


























































