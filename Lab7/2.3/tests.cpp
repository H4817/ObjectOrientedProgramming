#define BOOST_TEST_MODULE MyTestModule

#include <boost/test/included/unit_test.hpp>
#include "MyList.h"

struct MyListStructure
{
    CMyList<std::string> myStringList;
    CMyList<int> myIntList;
};

void PushStrings(CMyList<std::string> &myStringList)
{
    myStringList.PushBack("test1");
    myStringList.PushBack("test2");
    myStringList.PushBack("test3");
}

std::vector<std::string> GetStringVector()
{
    return std::vector<std::string>{"test1", "test2", "test3"};
}

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
        PushStrings(myStringList);
        CMyList<std::string> myStringList1(myStringList);
        CMyList<std::string> myStringList2 = myStringList1;
        BOOST_CHECK(myStringList1.GetBackElement() == "test3");
        BOOST_CHECK(myStringList1.GetSize());
        BOOST_CHECK(myStringList2.GetBackElement() == "test3");
        BOOST_CHECK(myStringList2.GetSize());
    }

    BOOST_AUTO_TEST_CASE(should_clear_an_instance)
    {
        PushStrings(myStringList);
        BOOST_CHECK(myStringList.GetSize());
        BOOST_CHECK_NO_THROW(myStringList.Clear());
        BOOST_CHECK(!myStringList.GetSize());
    }

    BOOST_AUTO_TEST_CASE(should_traverse_a_sequence_through_iterator)
    {
        PushStrings(myStringList);
        auto vec = GetStringVector();
        int counter = 0;
        for (auto it = myStringList.begin(); it != myStringList.end(); ++it)
        {
            BOOST_CHECK(*it == vec[counter]);
            ++counter;
        }
    }

    BOOST_AUTO_TEST_CASE(should_traverse_a_sequence_through_reverse_iterator)
    {
        PushStrings(myStringList);
        auto vec = GetStringVector();
        auto counter = vec.size() - 1;
        for (auto it = myStringList.rbegin(); it != myStringList.rend(); ++it)
        {
            BOOST_CHECK(*it == vec[counter]);
            --counter;
        }
    }

    BOOST_AUTO_TEST_CASE(should_insert_a_value_at_iterator_pos)
    {
        PushStrings(myStringList);
        myStringList.Insert(myStringList.begin(), "begin");
        BOOST_CHECK_EQUAL(*myStringList.begin(), "begin");
        myStringList.Insert(myStringList.end(), "end");
        myStringList.Insert(++myStringList.begin(), "test0");

        std::vector<std::string> expectedStr = {"begin", "test0", "test1", "test2", "test3", "end"};
        unsigned short counter = 0;
        for (auto it = myStringList.begin(); it != myStringList.end(); ++it)
        {
            BOOST_CHECK(*it == expectedStr[counter]);
            ++counter;
        }
    }

    BOOST_AUTO_TEST_CASE(should_erase_a_value_at_iterator_pos)
    {
        PushStrings(myStringList);
        BOOST_CHECK_NO_THROW(myStringList.Erase(++myStringList.begin()));
        BOOST_CHECK(*myStringList.begin() == "test1");
        BOOST_CHECK(*++myStringList.begin() == "test3");
        BOOST_CHECK_NO_THROW(myStringList.Erase(myStringList.begin()));
        BOOST_CHECK(*myStringList.begin() == "test3");
    }

BOOST_AUTO_TEST_SUITE_END()


























































