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
#include <SFML/Graphics.hpp>
#include "LineSegmentView.h"
#include "TriangleView.h"
#include "CircleView.h"
#include "RectangleView.h"
#include <stdlib.h>

using namespace std;

void SetColor(Color &color)
{
    std::string str;
    cin >> str;
    auto colorValue = stoi(str.substr(1), 0, 16);
    color.r = colorValue / 0x10000;
    color.g = (colorValue / 0x100) % 0x100;
    color.b = colorValue % 0x100;
}

void AddPoint(vector<std::shared_ptr<IShape>> &shapes)
{
    Color lineColor;
    std::pair<int, int> coordinates;
    cin >> coordinates.first >> coordinates.second;
    SetColor(lineColor);
    shapes.push_back(std::make_shared<CPoint>(CPoint(coordinates, lineColor)));
}

void AddLineSegment(vector<std::shared_ptr<IShape>> &shapes)
{
    Color color;
    std::pair<int, int> firstPoint;
    std::pair<int, int> secondPoint;
    cin >> firstPoint.first >> firstPoint.second >> secondPoint.first >> secondPoint.second;
    SetColor(color);
    shapes.push_back(make_shared<CLineSegment>(CLineSegment(firstPoint, secondPoint, color)));
}

void AddCircle(vector<std::shared_ptr<IShape>> &shapes)
{
    Color lineColor;
    Color backgroundColor;
    std::pair<int, int> center;
    int radius;
    cin >> center.first >> center.second >> radius;
    SetColor(lineColor);
    SetColor(backgroundColor);
    shapes.push_back(std::make_shared<CCircle>(CCircle(center, radius, lineColor, backgroundColor)));
}

void AddRectangle(vector<std::shared_ptr<IShape>> &shapes)
{
    Color lineColor;
    Color backgroundColor;
    std::pair<int, int> coordinatesOfPoint;
    std::pair<int, int> widthAndHeight;
    cin >> coordinatesOfPoint.first >> coordinatesOfPoint.second >> widthAndHeight.first >>
    widthAndHeight.second;
    SetColor(lineColor);
    SetColor(backgroundColor);
    shapes.push_back(std::make_shared<CRectangle>(
            CRectangle(coordinatesOfPoint, widthAndHeight, lineColor, backgroundColor)));
}

void AddTriangle(vector<std::shared_ptr<IShape>> &shapes)
{
    Color lineColor;
    Color backgroundColor;
    std::pair<int, int> firstPoint;
    std::pair<int, int> secondPoint;
    std::pair<int, int> thirdPoint;

    cin >> firstPoint.first >> firstPoint.second >> secondPoint.first >> secondPoint.second >>
    thirdPoint.first >> thirdPoint.second;
    SetColor(lineColor);
    SetColor(backgroundColor);
    shapes.push_back(std::make_shared<CTriangle>(
            CTriangle(firstPoint, secondPoint, thirdPoint, lineColor, backgroundColor)));
}

void PrintSortedByPerimeter(vector<std::shared_ptr<IShape>> &shapes)
{
    typedef std::shared_ptr<IShape> IShapePtr;
    std::sort(shapes.begin(), shapes.end(),
              [](std::shared_ptr<IShape> const &shape1, std::shared_ptr<IShape> const &shape2)
              {
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

void WorkWithUser()
{
    vector<std::shared_ptr<IShape>> shapes;
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
        if (shape == "Point")
        {
            AddPoint(shapes);
        }
        else if (shape == "LineSegment")
        {
            AddLineSegment(shapes);
        }
        else if (shape == "Triangle")
        {
            AddTriangle(shapes);
        }
        else if (shape == "Rectangle")
        {
            AddRectangle(shapes);
        }
        else if (shape == "Circle")
        {
            AddCircle(shapes);
        }
        else
        {
            std::cout << "unknown command: " << shape << std::endl;
            break;
        }
    }
}

int main()
{
    WorkWithUser();
    return 0;
}