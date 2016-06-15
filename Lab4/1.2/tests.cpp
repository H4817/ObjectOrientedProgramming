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
    struct TriangleHolder
    {
        CTriangle triangle;
        Color expectedLineColor = {17, 3, 0};
        Color expectedBackgroundColor = {1, 2, 1};
        double expectedPerimeter = 6.4721359549995796;
        double expectedArea = 2;
        std::string expectedString = "Triangle x1=1 y1=1 x2=3 y2=1 x3=2 y3=3 First side=2 Second side=2.23607 Third side=2.23607 P=6.47214 S=2";

        TriangleHolder() : triangle({1, 1}, {3, 1}, {2, 3}, expectedLineColor, expectedBackgroundColor)
        { }
    };

    struct RectangleHolder
    {
        CRectangle rectangle;
        Color expectedLineColor = {1, 3, 4};
        Color expectedBackgroundColor = {2, 1, 6};
        double expectedPerimeter = 58;
        double expectedArea = 198;
        std::string expectedString = "Rectangle x=10 y=12 width=18 height=11 P=58 S=198";

        RectangleHolder() : rectangle({10, 12}, {18, 11}, expectedLineColor, expectedBackgroundColor)
        { }
    };

    struct CircleHolder
    {
        CCircle circle;
        Color expectedColor = {10, 11, 12};
        std::pair<int, int> expectedCenter = {8, 8};
        int expectedRadius = 5;
        double expectedPerimeter = 31.415926535897931;
        double expectedArea = 78.539816339744831;
        std::string expectedString = "Circle x=8 y=8 R=5 P=31.4159 S=78.5398";

        CircleHolder() : circle({8, 8}, 5, expectedColor, expectedColor)
        { }
    };

    struct PointHolder
    {
        CPoint point;
        Color expectedColor = {0, 1, 2};
        unsigned short expectedPerimeter = 0;
        unsigned short expectedArea = 0;
        std::string expectedString = "Point x=10 y=12 P=0 S=0";

        PointHolder()
                : point({10, 12}, expectedColor)
        { }
    };

    struct LineSegmentHolder
    {
        CLineSegment line;
        Color expectedColor = {10, 11, 12};
        double expectedPerimeter = 7.2111025509279782;
        unsigned expectedArea = 0;
        std::string expectedString = "LineSegment x1=10 y1=12 x2=14 y2=18 P=7.2111 S=0";

        LineSegmentHolder()
                : line({10, 12}, {14, 18}, expectedColor)
        { }
    };
};

struct ShapesHolder
{
    CShapesFixture::PointHolder pointHolder;
    CShapesFixture::LineSegmentHolder lineSegmentHolder;
    CShapesFixture::CircleHolder circleHolder;
    CShapesFixture::RectangleHolder rectangleHolder;
    CShapesFixture::TriangleHolder triangleHolder;
};

BOOST_FIXTURE_TEST_SUITE(Shapes, ShapesHolder)

    BOOST_AUTO_TEST_SUITE(tests_for_point)

        BOOST_AUTO_TEST_CASE(check_perimeter)
        {
            BOOST_CHECK_EQUAL(pointHolder.point.GetPerimeter(), pointHolder.expectedPerimeter);
        }

        BOOST_AUTO_TEST_CASE(check_area)
        {
            BOOST_CHECK_EQUAL(pointHolder.point.GetArea(), pointHolder.expectedArea);
        }

        BOOST_AUTO_TEST_CASE(check_ToString_method)
        {
            BOOST_CHECK_EQUAL(pointHolder.point.ToString(), pointHolder.expectedString);
        }

        BOOST_AUTO_TEST_CASE(check_color)
        {
            BOOST_CHECK(pointHolder.point.GetLineColor() == pointHolder.expectedColor);
        }

    BOOST_AUTO_TEST_SUITE_END()


    BOOST_AUTO_TEST_SUITE(tests_for_line_segment)

        BOOST_AUTO_TEST_CASE(check_perimeter)
        {
            BOOST_CHECK_EQUAL(lineSegmentHolder.line.GetPerimeter(), lineSegmentHolder.expectedPerimeter);
        }

        BOOST_AUTO_TEST_CASE(check_area)
        {
            BOOST_CHECK_EQUAL(lineSegmentHolder.line.GetArea(), lineSegmentHolder.expectedArea);
        }

        BOOST_AUTO_TEST_CASE(check_ToString_method)
        {
            BOOST_CHECK_EQUAL(lineSegmentHolder.line.ToString(), lineSegmentHolder.expectedString);
        }

        BOOST_AUTO_TEST_CASE(check_color)
        {
            BOOST_CHECK(lineSegmentHolder.line.GetLineColor() == lineSegmentHolder.expectedColor);
        }

    BOOST_AUTO_TEST_SUITE_END()


    BOOST_AUTO_TEST_SUITE(tests_for_circle)

        BOOST_AUTO_TEST_CASE(check_perimeter)
        {
            BOOST_CHECK_EQUAL(circleHolder.circle.GetPerimeter(), circleHolder.expectedPerimeter);
        }

        BOOST_AUTO_TEST_CASE(check_area)
        {
            BOOST_CHECK_EQUAL(circleHolder.circle.GetArea(), circleHolder.expectedArea);
        }

        BOOST_AUTO_TEST_CASE(check_ToString_method)
        {
            BOOST_CHECK_EQUAL(circleHolder.circle.ToString(), circleHolder.expectedString);
        }

        BOOST_AUTO_TEST_CASE(check_color)
        {
            BOOST_CHECK(circleHolder.circle.GetLineColor() == circleHolder.expectedColor);
            BOOST_CHECK(circleHolder.circle.GetBackgroundColor() == circleHolder.expectedColor);
        }

    BOOST_AUTO_TEST_SUITE_END()

    BOOST_AUTO_TEST_SUITE(tests_for_rectangle)

        BOOST_AUTO_TEST_CASE(check_perimeter)
        {
            BOOST_CHECK_EQUAL(rectangleHolder.rectangle.GetPerimeter(), rectangleHolder.expectedPerimeter);
        }

        BOOST_AUTO_TEST_CASE(check_area)
        {
            BOOST_CHECK_EQUAL(rectangleHolder.rectangle.GetArea(), rectangleHolder.expectedArea);
        }

        BOOST_AUTO_TEST_CASE(check_ToString_method)
        {
            BOOST_CHECK_EQUAL(rectangleHolder.rectangle.ToString(), rectangleHolder.expectedString);
        }

        BOOST_AUTO_TEST_CASE(check_color)
        {
            BOOST_CHECK(rectangleHolder.rectangle.GetLineColor() == rectangleHolder.expectedLineColor);
            BOOST_CHECK(rectangleHolder.rectangle.GetBackgroundColor() == rectangleHolder.expectedBackgroundColor);
        }

    BOOST_AUTO_TEST_SUITE_END()


    BOOST_AUTO_TEST_SUITE(tests_for_triangle)

        BOOST_AUTO_TEST_CASE(check_perimeter)
        {
            BOOST_CHECK_EQUAL(triangleHolder.triangle.GetPerimeter(), triangleHolder.expectedPerimeter);
        }

        BOOST_AUTO_TEST_CASE(check_area)
        {
            BOOST_CHECK_EQUAL(triangleHolder.triangle.GetArea(), triangleHolder.expectedArea);
        }

        BOOST_AUTO_TEST_CASE(check_ToString_method)
        {
            BOOST_CHECK_EQUAL(triangleHolder.triangle.ToString(), triangleHolder.expectedString);
        }

        BOOST_AUTO_TEST_CASE(check_color)
        {
            BOOST_CHECK(triangleHolder.triangle.GetLineColor() == triangleHolder.expectedLineColor);
            BOOST_CHECK(triangleHolder.triangle.GetBackgroundColor() == triangleHolder.expectedBackgroundColor);
        }

    BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()


