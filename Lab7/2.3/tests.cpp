#define BOOST_TEST_MODULE MyTestModule

#include <boost/test/included/unit_test.hpp>
#include "MyList.h"

struct MyListStructure
{
    CMyList <std::string> myStringList;
    CMyList <int> myIntList;
};

BOOST_FIXTURE_TEST_SUITE(initialization_tests, MyListStructure)
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

        BOOST_CHECK_NO_THROW(myStringList.PushBack("123"));
        BOOST_CHECK_NO_THROW(myStringList.PushBack("test"));
        BOOST_CHECK_NO_THROW(myStringList.PushBack());

        BOOST_CHECK_NO_THROW(myIntList.PushFront(3));
        BOOST_CHECK_NO_THROW(myIntList.PushFront(1.f));
        BOOST_CHECK_NO_THROW(myIntList.PushFront());
        CMyList <std::string> cMyList4;
        BOOST_CHECK_NO_THROW(cMyList4.PushFront("123"));
        BOOST_CHECK_NO_THROW(cMyList4.PushFront("test"));
        BOOST_CHECK_NO_THROW(cMyList4.PushFront());
    }
    
    BOOST_AUTO_TEST_CASE(should_pass_when_list_is_empty)
    {
        BOOST_CHECK(myStringList.IsEmpty());
        myStringList.PushBack("word");
        BOOST_CHECK(!myStringList.IsEmpty());
    }

    BOOST_AUTO_TEST_CASE(should_return_back_element)
    {
        myIntList.PushBack(4);
        BOOST_CHECK_EQUAL(myIntList.GetBackElement(), 4);
        myStringList.PushBack("test");
        BOOST_CHECK_EQUAL(myStringList.GetBackElement(), "test");
    }

BOOST_AUTO_TEST_SUITE_END()


























































