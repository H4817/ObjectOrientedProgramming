#define BOOST_TEST_MODULE MyTestModule

#include <boost/test/included/unit_test.hpp>
#include "Shape.h"
#include "LineSegment.h"
#include "Triangle.h"
#include "Point.h"
#include "Rectangle.h"
#include "Circle.h"

struct CShapesFixture
{
    struct Triangle
    {
        std::pair<int, int> firstPoint;
        std::pair<int, int> secondPoint;
        std::pair<int, int> thirdPoint;
    } triangle;

    struct Rectangle
    {
        std::pair<int, int> coordinatesOfPoint;
        std::pair<int, int> widthAndHeight;
    } rectangle;

    struct Circle
    {
        std::pair<int, int> center;
        int radius;
    } circle;

    struct Point
    {
        std::pair<int, int> coordinates;
    } point;

    struct LineSegment
    {
        std::pair<int, int> firstPoint;
        std::pair<int, int> secondPoint;
    } lineSegment;
};

BOOST_FIXTURE_TEST_SUITE(Car, CCarFixture)

    BOOST_AUTO_TEST_CASE()
    {

    }

BOOST_AUTO_TEST_SUITE_END()

