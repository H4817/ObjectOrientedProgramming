#define BOOST_TEST_MODULE MyTestModule

#include <boost/test/included/unit_test.hpp>
#include "MyList.h"

struct MyListStructure
{
    CMyList<std::string> myStringList;
    CMyList<int> myIntList;
};

BOOST_FIXTURE_TEST_SUITE(initialization_tests, MyListStructure)

    BOOST_AUTO_TEST_CASE(should_being_initialized_by_default_value_type)
    {
        BOOST_CHECK_NO_THROW(CMyList<int> cMyList1);
    }

    BOOST_AUTO_TEST_CASE(should_push_numbers_and_strings)
    {
        CMyList<int> cMyList1;
        BOOST_CHECK_NO_THROW(cMyList1.PushBack(3));
        BOOST_CHECK_NO_THROW(cMyList1.PushBack(1.f));
        BOOST_CHECK_NO_THROW(cMyList1.PushBack());

        BOOST_CHECK_NO_THROW(myStringList.PushBack("123"));
        BOOST_CHECK_NO_THROW(myStringList.PushBack("test"));
        BOOST_CHECK_NO_THROW(myStringList.PushBack());

        BOOST_CHECK_NO_THROW(myIntList.PushFront(3));
        BOOST_CHECK_NO_THROW(myIntList.PushFront(1.f));
        BOOST_CHECK_NO_THROW(myIntList.PushFront());
        CMyList<std::string> cMyList4;
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

    BOOST_AUTO_TEST_CASE(should_copy_an_instance)
    {
        CMyList<std::string> myStringList1;
        myStringList1.PushBack("test");
        CMyList<std::string> myStringList2;
        CMyList<std::string> myStringList3(myStringList1);
        myStringList2 = myStringList1;
        BOOST_CHECK(myStringList2.GetBackElement() == "test");
        BOOST_CHECK(myStringList2.GetSize());
        BOOST_CHECK(myStringList3.GetBackElement() == "test");
        BOOST_CHECK(myStringList3.GetSize());
    }

    BOOST_AUTO_TEST_CASE(should_clear_an_instance)
    {
        myStringList.PushBack("test1");
        myStringList.PushBack("test2");
        myStringList.PushBack("test3");
        BOOST_CHECK(myStringList.GetSize());
        BOOST_CHECK_NO_THROW(myStringList.Clear());
        BOOST_CHECK(!myStringList.GetSize());
    }

    BOOST_AUTO_TEST_CASE(should_traverse_a_sequence_through_iterator)
    {
        myStringList.PushBack("test1");
        myStringList.PushBack("test2");
        myStringList.PushBack("test3");
        for (auto it = myStringList.begin(); it != myStringList.end(); ++it)
        {
            std::cout << myStringList.GetSize() << std::endl;
        }
    }

    BOOST_AUTO_TEST_CASE(should_traverse_a_sequence_through_reverse_iterator)
    {
        myStringList.PushBack("test1");
        myStringList.PushBack("test2");
        for (auto it = myStringList.rbegin(); it != myStringList.rend(); ++it)
        {
            std::cout << myStringList.GetSize() << std::endl;
        }
    }

BOOST_AUTO_TEST_SUITE_END()


























































