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
        BOOST_CHECK_NO_THROW(cMyList1.PushBack(3));
        BOOST_CHECK_NO_THROW(cMyList1.PushBack(1.f));
        BOOST_CHECK_NO_THROW(cMyList1.PushBack());
        CMyList <std::string> cMyList2;
        BOOST_CHECK_NO_THROW(cMyList2.PushBack("123"));
        BOOST_CHECK_NO_THROW(cMyList2.PushBack("test"));
        BOOST_CHECK_NO_THROW(cMyList2.PushBack());

        CMyList <int> cMyList3;
        BOOST_CHECK_NO_THROW(cMyList3.PushFront(3));
        BOOST_CHECK_NO_THROW(cMyList3.PushFront(1.f));
        BOOST_CHECK_NO_THROW(cMyList3.PushFront());
        CMyList <std::string> cMyList4;
        BOOST_CHECK_NO_THROW(cMyList4.PushFront("123"));
        BOOST_CHECK_NO_THROW(cMyList4.PushFront("test"));
        BOOST_CHECK_NO_THROW(cMyList4.PushFront());
    }

BOOST_AUTO_TEST_SUITE_END()


























































