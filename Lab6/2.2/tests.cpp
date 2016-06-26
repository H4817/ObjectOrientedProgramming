#define BOOST_TEST_MODULE MyTestModule

#include <boost/test/included/unit_test.hpp>
#include "StringList.h"

struct StringListStructure
{
    CStringList myStringList;
};

void PushStrings(CStringList &myStringList)
{
    myStringList.PushBack("test1");
    myStringList.PushBack("test2");
    myStringList.PushBack("test3");
}

std::vector<std::string> GetStringVector()
{
    return std::vector<std::string>{"test1", "test2", "test3"};
}

BOOST_FIXTURE_TEST_SUITE(string_list_tests, StringListStructure)

    BOOST_AUTO_TEST_CASE(should_push_back_strings)
    {
        BOOST_CHECK_NO_THROW(myStringList.PushBack("test0"));
        BOOST_CHECK(myStringList.GetBackElement() == "test0");
        BOOST_CHECK_NO_THROW(PushStrings(myStringList));
        BOOST_CHECK(myStringList.GetBackElement() == "test3");
    }

    BOOST_AUTO_TEST_CASE(should_push_front_strings)
    {
        BOOST_CHECK_NO_THROW(myStringList.PushFront("test"));
        BOOST_CHECK(myStringList.GetFrontElement() == "test");
        BOOST_CHECK_NO_THROW(PushStrings(myStringList));
        BOOST_CHECK_NO_THROW(myStringList.PushFront("test0"));
        BOOST_CHECK(myStringList.GetFrontElement() == "test0");
    }
    
    BOOST_AUTO_TEST_CASE(should_pass_when_list_is_empty)
    {
        BOOST_CHECK(myStringList.IsEmpty());
        myStringList.PushBack("word");
        BOOST_CHECK(!myStringList.IsEmpty());
    }

    BOOST_AUTO_TEST_CASE(should_copy_an_instance)
    {
        PushStrings(myStringList);
        CStringList myStringList1(myStringList);
        CStringList myStringList2 = myStringList1;
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
        BOOST_CHECK(std::equal(myStringList.begin(), myStringList.end(), vec.begin()));
    }

    BOOST_AUTO_TEST_CASE(should_traverse_a_sequence_through_reverse_iterator)
    {
        PushStrings(myStringList);
        auto vec = GetStringVector();
        BOOST_CHECK(std::equal(myStringList.rbegin(), myStringList.rend(), vec.rbegin()));
    }

    BOOST_AUTO_TEST_CASE(should_insert_a_value_at_iterator_pos)
    {
        PushStrings(myStringList);
        myStringList.Insert(myStringList.begin(), "begin");
        BOOST_CHECK_EQUAL(*myStringList.begin(), "begin");
        myStringList.Insert(myStringList.end(), "end");
        myStringList.Insert(++myStringList.begin(), "test0");
        std::vector<std::string> expectedStr = {"begin", "test0", "test1", "test2", "test3", "end"};
        BOOST_CHECK(std::equal(myStringList.begin(), myStringList.end(), expectedStr.begin()));
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

