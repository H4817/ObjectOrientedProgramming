#define BOOST_TEST_MODULE MyTestModule

#include <boost/test/included/unit_test.hpp>
#include "Car.h"

BOOST_AUTO_TEST_SUITE(CCalculator_tests)

    CCar car;

    BOOST_AUTO_TEST_CASE(TurnOnEngine)
    {
        BOOST_CHECK(car.TurnOnEngine());
    }

    BOOST_AUTO_TEST_CASE(SetGear1)
    {
        BOOST_CHECK(car.SetGear(1));
    }

    BOOST_AUTO_TEST_CASE(SetSpeed30)
    {
        BOOST_CHECK(car.SetSpeed(30));
    }

    BOOST_AUTO_TEST_CASE(SetGear2)
    {
        BOOST_CHECK(car.SetGear(2));
    }

    BOOST_AUTO_TEST_CASE(SetSpeed50)
    {
        BOOST_CHECK(car.SetSpeed(50));
    }

    BOOST_AUTO_TEST_CASE(SetGear3)
    {
        BOOST_CHECK(car.SetGear(3));
    }

    BOOST_AUTO_TEST_CASE(SetSpeed60)
    {
        BOOST_CHECK(car.SetSpeed(60));
    }

    BOOST_AUTO_TEST_CASE(SetGear4)
    {
        BOOST_CHECK(car.SetGear(4));
    }

    BOOST_AUTO_TEST_CASE(SetSpeed90)
    {
        BOOST_CHECK(car.SetSpeed(90));
    }

    BOOST_AUTO_TEST_CASE(SetGear5)
    {
        BOOST_CHECK(car.SetGear(5));
    }

    BOOST_AUTO_TEST_CASE(SetSpeed150)
    {
        BOOST_CHECK(car.SetSpeed(150));
    }

    BOOST_AUTO_TEST_CASE(TurnOffEngine)
    {
        BOOST_CHECK(car.TurnOffEngine());
    }



BOOST_AUTO_TEST_SUITE_END()
