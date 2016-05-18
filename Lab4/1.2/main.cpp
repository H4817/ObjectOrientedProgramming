#include <iostream>
#include <vector>
#include "Shape.h"
#include "LineSegment.h"
#include "Triangle.h"
#include "Point.h"
#include "Rectangle.h"
#include "Circle.h"
#include <algorithm>
#include <memory>

using namespace std;

void PrintSortedByPerimeter(vector<std::shared_ptr<IShape>> &shapes)
{
    typedef std::shared_ptr <IShape> IShapePtr;
    std::sort(shapes.begin(), shapes.end(), [](std::shared_ptr <IShape> const &shape1, std::shared_ptr <IShape> const &shape2) {
                  return shape1->GetArea() > shape2->GetArea();
    });
    for (auto it : shapes)
    {
        cout << it->ToString() << endl;
    }
    cout << "=======================================" << endl;
}

void PrintSortedByArea(vector<std::shared_ptr<IShape>> &shapes)
{
    // TODO: fix style
    std::sort(shapes.begin(), shapes.end(),
              [](std::shared_ptr<IShape> const &shape1, std::shared_ptr<IShape> const &shape2)
              {
                  return shape1->GetPerimeter() > shape2->GetPerimeter();
              });
    for (auto it : shapes)
    {
        cout << it->ToString() << endl;
    }
}

void WorkWithUser(vector<std::shared_ptr<IShape>> &shapes, Color &lineColor, Color &backgroundColor)
{
    cout << "Type some commands or press q for exit" << endl;
    string shape;
    for (; ;)
    {
        cout << "> ";
        cin >> shape;
        if (shape == "q")
        {
            PrintSortedByPerimeter(shapes);
            PrintSortedByArea(shapes);
            break;
        }
        if (shape == "LineSegment")
        {
            std::pair<int, int> firstPoint;
            std::pair<int, int> secondPoint;
            cin >> firstPoint.first >> firstPoint.second >> secondPoint.first >> secondPoint.second;
            shapes.push_back(make_shared<CLineSegment>(CLineSegment(firstPoint, secondPoint)));
        }
        else if (shape == "Point")
        {
            std::pair<int, int> coordinates;
            cin >> coordinates.first >> coordinates.second;
            shapes.push_back(std::make_shared<CPoint>(CPoint(coordinates)));
        }
        else if (shape == "Triangle")
        {
            std::pair<int, int> firstPoint;
            std::pair<int, int> secondPoint;
            std::pair<int, int> thirdPoint;

            cin >> firstPoint.first >> firstPoint.second >> secondPoint.first >> secondPoint.second >>
            thirdPoint.first >> thirdPoint.second;
            shapes.push_back(std::make_shared<CTriangle>(CTriangle(firstPoint, secondPoint, thirdPoint)));
        }
        else if (shape == "Rectangle")
        {
            std::pair<int, int> coordinatesOfPoint;
            std::pair<int, int> widthAndHeight;
            cin >> coordinatesOfPoint.first >> coordinatesOfPoint.second >> widthAndHeight.first >>
            widthAndHeight.second;
            shapes.push_back(std::make_shared<CRectangle>(CRectangle(coordinatesOfPoint, widthAndHeight)));
        }
        else if (shape == "Circle")
        {
            std::pair<int, int> center;
            int radius;
            cin >> center.first >> center.second >> radius;
            shapes.push_back(std::make_shared<CCircle>(CCircle(center, radius)));
        }
    }
}

int main()
{
    Color backgroundColor;
    Color lineColor;
    vector<std::shared_ptr<IShape>> shapes;
    WorkWithUser(shapes, lineColor, backgroundColor);
    return 0;
}