#define BOOST_TEST_MODULE MyTestModule

#include <boost/test/included/unit_test.hpp>
#include "HttpUrl.h"
#include "UrlParsingError.h"

BOOST_AUTO_TEST_SUITE(passing_url)

    BOOST_AUTO_TEST_CASE(throws_parsing_error_if_url_is_empty)
    {
        BOOST_CHECK_THROW(CHttpUrl url(""), CUrlParsingError);
    }

    BOOST_AUTO_TEST_CASE(throws_parsing_error_if_protocol_is_incorrect)
    {
        BOOST_CHECK_THROW(CHttpUrl url("ftp://"), CUrlParsingError);
        BOOST_CHECK_THROW(CHttpUrl url("html://"), CUrlParsingError);
        BOOST_CHECK_NO_THROW(CHttpUrl url("http://google.com/abc.jpeg"));
        BOOST_CHECK_NO_THROW(CHttpUrl url("https://yandex.com/abc.jpeg"));
    }

    BOOST_AUTO_TEST_CASE(throws_parsing_error_if_incorrect_format_after_protocol)
    {
        BOOST_CHECK_THROW(CHttpUrl url("http::/"), CUrlParsingError);
        BOOST_CHECK_THROW(CHttpUrl url("http::///"), CUrlParsingError);
        BOOST_CHECK_NO_THROW(CHttpUrl url("http://testx.com/abc.jpeg"));
        BOOST_CHECK_NO_THROW(CHttpUrl url("https://random.com"));
    }

    BOOST_AUTO_TEST_CASE(throws_parsing_error_if_domain_is_empty_or_contains_whitespaces)
    {
        BOOST_CHECK_THROW(CHttpUrl url("http://ga me .com"), CUrlParsingError);
        BOOST_CHECK_THROW(CHttpUrl url("http://		r"), CUrlParsingError);
        BOOST_CHECK_NO_THROW(CHttpUrl url("http://tower.com"));
        BOOST_CHECK_NO_THROW(CHttpUrl url("https://rofl.com/abc.jpeg"));
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


BOOST_AUTO_TEST_SUITE(per_component_constructor)

    BOOST_AUTO_TEST_CASE(getting_parts_of_url)
    {
        CHttpUrl url1("localhost", "images/img", Protocol::HTTPS, 666);
        CHttpUrl url2("lol.com", "/", Protocol::HTTP, 329);

        BOOST_CHECK_EQUAL(url1.GetDocument(), "/images/img");
        BOOST_CHECK_EQUAL(url1.GetDomain(), "localhost");
        BOOST_CHECK(url1.GetPort() == 666);
        BOOST_CHECK_EQUAL(url1.GetURL(), "https://localhost:666/images/img");

        BOOST_CHECK_EQUAL(url2.GetDocument(), "/");
        BOOST_CHECK_EQUAL(url2.GetDomain(), "lol.com");
        BOOST_CHECK(url2.GetPort() == 329);
        BOOST_CHECK_EQUAL(url2.GetURL(), "http://lol.com:329/");
    }

    BOOST_AUTO_TEST_CASE(default_ports_are_not_including_in_the_url)
    {
        CHttpUrl url1("https://cpp.com:443/");
        CHttpUrl url2("http://python.com:80/abc/asd/");
        BOOST_CHECK_EQUAL(url1.GetURL(), "https://cpp.com/");
        BOOST_CHECK_EQUAL(url2.GetURL(), "http://python.com/abc/asd/");
    }

BOOST_AUTO_TEST_SUITE_END()



