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

    BOOST_AUTO_TEST_CASE(displaying_standart_port)
    {
        CHttpUrl url0("https://google.com:443");
        BOOST_CHECK_EQUAL((url0.GetURL()), ("https://google.com"));
        CHttpUrl url("http://test.com:80");
        BOOST_CHECK_EQUAL((url.GetURL()), ("http://test.com"));
        CHttpUrl url1("http://yandex.com:81/index.php");
        BOOST_CHECK_EQUAL((url1.GetURL()), ("http://yandex.com:81/index.php"));
        CHttpUrl url2("http://game.com:8080");
        BOOST_CHECK_EQUAL((url2.GetURL()), ("http://game.com:8080"));
    }

    // TODO: test case with per-component constructor
    //   - "http://localhost"

BOOST_AUTO_TEST_SUITE_END()

