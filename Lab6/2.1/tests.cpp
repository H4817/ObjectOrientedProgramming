#define BOOST_TEST_MODULE MyTestModule

#include <boost/test/included/unit_test.hpp>
#include "StringStack.h"

BOOST_AUTO_TEST_SUITE(string_stack_test)

    BOOST_AUTO_TEST_CASE(initializer_list)
    {
        BOOST_CHECK_NO_THROW(CStringStack cStringStack);
        BOOST_CHECK_NO_THROW(CStringStack cStringStack1("https://game.com:65f545"));
    }

    BOOST_AUTO_TEST_CASE(compare_with_expecting)
    {
        CStringStack cStringStack("test");
        auto item = cStringStack.InitializeNode("test1");
        std::string data = item->data;
        BOOST_CHECK_EQUAL(data, "tessdasft");
    }

BOOST_AUTO_TEST_SUITE_END()