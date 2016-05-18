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
        CPoint point;

        PointFixture()
                :point(10, 20)
        {

        }
    };

    struct LineSegment
    {
        CLineSegment line;

        LineFixture()
                : line(CPoint(1, 1), CPoint(3, 3))
        {

        }
    };
};

BOOST_FIXTURE_TEST_SUITE(Shapes, CShapesFixture)

    BOOST_AUTO_TEST_CASE()
    {

    }

BOOST_AUTO_TEST_SUITE_END()

