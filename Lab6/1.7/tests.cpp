#define BOOST_TEST_MODULE MyTestModule

#include <boost/test/included/unit_test.hpp>
#include "HttpUrl.h"
#include "UrlParsingError.h"

BOOST_AUTO_TEST_SUITE(after_passing_url_to_constructor_as_string)

    BOOST_AUTO_TEST_CASE(throws_parsing_error_if_url_is_empty)
    {
        BOOST_CHECK_THROW(CHttpUrl url(""), CUrlParsingError);
    }

    BOOST_AUTO_TEST_CASE(throws_parsing_error_if_protocol_is_incorrect)
    {
        BOOST_CHECK_THROW(CHttpUrl url("ftp://"), CUrlParsingError);
        BOOST_CHECK_THROW(CHttpUrl url("html://"), CUrlParsingError);
        BOOST_CHECK_NO_THROW(CHttpUrl url("http://game.com/abc.jpeg"));
        BOOST_CHECK_NO_THROW(CHttpUrl url("https://game.com/abc.jpeg"));
    }
    BOOST_AUTO_TEST_CASE(throws_parsing_error_if_incorrect_format_after_protocol)
    {
        BOOST_CHECK_THROW(CHttpUrl url("http::/"), CUrlParsingError);
        BOOST_CHECK_THROW(CHttpUrl url("http::///"), CUrlParsingError);
        BOOST_CHECK_NO_THROW(CHttpUrl url("http://game.com/abc.jpeg"));
        BOOST_CHECK_NO_THROW(CHttpUrl url("https://game.com"));
    }
    BOOST_AUTO_TEST_CASE(throws_parsing_error_if_domain_is_empty_or_contains_whitespaces)
    {
        BOOST_CHECK_THROW(CHttpUrl url("http://ga me .com"), CUrlParsingError);
        BOOST_CHECK_THROW(CHttpUrl url("http://		r"), CUrlParsingError);
        BOOST_CHECK_NO_THROW(CHttpUrl url("http://game.com"));
        BOOST_CHECK_NO_THROW(CHttpUrl url("https://game.com/abc.jpeg"));
    }
    BOOST_AUTO_TEST_CASE(throws_parsing_error_if_port_is_incorrect)
    {
        BOOST_CHECK_NO_THROW(CHttpUrl url("http://game.com:0"));
        BOOST_CHECK_NO_THROW(CHttpUrl url("https://game.com:65534"));
        BOOST_CHECK_THROW(CHttpUrl url("http://game.com:dfsf"), CUrlParsingError);
        BOOST_CHECK_THROW(CHttpUrl url("https://game.com:65f545"), CUrlParsingError);
        BOOST_CHECK_THROW(CHttpUrl url("https://game.com:9999999999999999999999999999999999999999"), CUrlParsingError);
        BOOST_CHECK_THROW(CHttpUrl url("https://game.com:-999"), CUrlParsingError);
    }
    BOOST_AUTO_TEST_CASE(throws_parsing_error_if_port_is_standart)
    {
        CHttpUrl url("http://game.com:80");
        BOOST_CHECK_EQUAL((CHttpUrl url.GetUrl()), ("http://game.com"));
    }


    // TODO: test case with per-component constructor
    //   - "http://localhost"
    // TODO: test case for ToString()
    //   - "http://localhost/index.php" and "http://localhost:80/index.php" and :8080

BOOST_AUTO_TEST_SUITE_END()

