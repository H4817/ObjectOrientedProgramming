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
#include <fstream>

using namespace std;

void DrawShapes(vector<std::shared_ptr<CShapeViewer>> &shapesView)
{
    sf::RenderWindow window;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    window.create(sf::VideoMode(800, 800), "Shapes", sf::Style::Default, settings);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::White);
        for (auto ptr : shapesView)
        {
            window.draw(*ptr);
        }
        window.display();
    }
}

void SetColor(Color &color, std::stringstream &sstream)
{
    std::string str;
    if (sstream.str() != "")
    {
        sstream >> str;
    }
    else
    {
        cin >> str;
    }
    auto colorValue = stoi(str.substr(1), 0, 16);
    color.r = colorValue / 0x10000;
    color.g = (colorValue / 0x100) % 0x100;
    color.b = colorValue % 0x100;
}

void AddPoint(vector<std::shared_ptr<IShape>> &shapes, std::stringstream &sstream)
{
    Color lineColor;
    std::pair<int, int> coordinates;
    if (sstream.str() != "")
    {
        sstream >> coordinates.first >> coordinates.second;
    }
    else
    {
        cin >> coordinates.first >> coordinates.second;
    }
    SetColor(lineColor, sstream);
    shapes.push_back(std::make_shared<CPoint>(CPoint(coordinates, lineColor)));
}

void AddLineSegment(vector<std::shared_ptr<IShape>> &shapes, vector<std::shared_ptr<CShapeViewer>> &shapesView,
                    std::stringstream &sstream)
{
    Color color;
    std::pair<int, int> firstPoint;
    std::pair<int, int> secondPoint;
    if (sstream.str() != "")
    {
        sstream >> firstPoint.first >> firstPoint.second >> secondPoint.first >> secondPoint.second;
    }
    else
    {
        cin >> firstPoint.first >> firstPoint.second >> secondPoint.first >> secondPoint.second;
    }
    SetColor(color, sstream);
    shapes.push_back(make_shared<CLineSegment>(CLineSegment(firstPoint, secondPoint, color)));
    shapesView.push_back(std::make_shared<CLineSegmentView>(
            CLineSegmentView({firstPoint.first, firstPoint.second},
                             {secondPoint.first, secondPoint.second}, color)));
}

void AddCircle(vector<std::shared_ptr<IShape>> &shapes, vector<std::shared_ptr<CShapeViewer>> &shapesView,
               std::stringstream &sstream)
{
    Color lineColor;
    Color backgroundColor;
    std::pair<int, int> center;
    int radius;
    if (sstream.str() != "")
    {
        sstream >> center.first >> center.second >> radius;
    }
    else
    {
        cin >> center.first >> center.second >> radius;
    }
    SetColor(lineColor, sstream);
    SetColor(backgroundColor, sstream);
    shapes.push_back(std::make_shared<CCircle>(CCircle(center, radius, lineColor, backgroundColor)));
    shapesView.push_back(std::make_shared<CCircleView>(
            CCircleView({center.first, center.second}, radius, lineColor,
                        backgroundColor)));
}

void AddRectangle(vector<std::shared_ptr<IShape>> &shapes, vector<std::shared_ptr<CShapeViewer>> &shapesView,
                  std::stringstream &sstream)
{
    Color lineColor;
    Color backgroundColor;
    std::pair<int, int> coordinatesOfPoint;
    std::pair<int, int> widthAndHeight;
    if (sstream.str() != "")
    {
        sstream >> coordinatesOfPoint.first >> coordinatesOfPoint.second >> widthAndHeight.first >>
        widthAndHeight.second;
    }
    else
    {
        cin >> coordinatesOfPoint.first >> coordinatesOfPoint.second >> widthAndHeight.first >>
        widthAndHeight.second;
    }
    SetColor(lineColor, sstream);
    SetColor(backgroundColor, sstream);
    shapes.push_back(std::make_shared<CRectangle>(
            CRectangle(coordinatesOfPoint, widthAndHeight, lineColor, backgroundColor)));
    shapesView.push_back(std::make_shared<CRectangleView>(
            CRectangleView(
                    {coordinatesOfPoint.first, coordinatesOfPoint.second},
                    {widthAndHeight.first, widthAndHeight.second}, lineColor,
                    backgroundColor)));
}

void AddTriangle(vector<std::shared_ptr<IShape>> &shapes, vector<std::shared_ptr<CShapeViewer>> &shapesView,
                 std::stringstream &sstream)
{
    Color lineColor;
    Color backgroundColor;
    std::pair<int, int> firstPoint;
    std::pair<int, int> secondPoint;
    std::pair<int, int> thirdPoint;
    if (sstream.str() != "")
    {

        sstream >> firstPoint.first >> firstPoint.second >> secondPoint.first >> secondPoint.second >>
        thirdPoint.first >> thirdPoint.second;
    }
    else
    {
        cin >> firstPoint.first >> firstPoint.second >> secondPoint.first >> secondPoint.second >>
        thirdPoint.first >> thirdPoint.second;
    }
    SetColor(lineColor, sstream);
    SetColor(backgroundColor, sstream);
    shapes.push_back(std::make_shared<CTriangle>(
            CTriangle(firstPoint, secondPoint, thirdPoint, lineColor, backgroundColor)));
    shapesView.push_back(std::make_shared<CTriangleView>(
            CTriangleView(
                    {firstPoint.first, firstPoint.second},
                    {secondPoint.first, secondPoint.second},
                    {thirdPoint.first, thirdPoint.second}, lineColor,
                    backgroundColor)));
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

bool CommandHandler(const string &command, std::stringstream &sstream)
{
    vector<std::shared_ptr<IShape>> shapes;
    vector<std::shared_ptr<CShapeViewer>> shapesView;
    if (command == "q")
    {
        PrintSortedByPerimeter(shapes);
        PrintSortedByArea(shapes);
        return false;
    }
    else if (command == "draw")
    {
        DrawShapes(shapesView);
        return true;
    }
    else if (command == "Point")
    {
        AddPoint(shapes, sstream);
        return true;
    }
    else if (command == "LineSegment")
    {
        AddLineSegment(shapes, shapesView, sstream);
        return true;
    }
    else if (command == "Triangle")
    {
        AddTriangle(shapes, shapesView, sstream);
        return true;
    }
    else if (command == "Rectangle")
    {
        AddRectangle(shapes, shapesView, sstream);
        return true;
    }
    else if (command == "Circle")
    {
        AddCircle(shapes, shapesView, sstream);
        return true;
    }
    return false;
}

void WorkWithUser(string fileName = "")
{
    cout << "<<<List of commands>>>\n";
    cout << "q - exit\n";
    cout << "draw - draw existed shapes\n";
    cout << "Point <x, y, color>\n";
    cout << "LineSegment <x1, y1, x2, y2, color>\n";
    cout << "Circle <x, y, r, lineColor, bgColor>\n";
    cout << "Rectangle <x, y, w, h, lineColor, bgColor>\n";
    cout << "Triangle <x1, y1, x2, y2, x3, y3, lineColor, bgColor>\n";
    cout << "<<<Another commands are not supported>>>\n";
    string command;
    if (fileName != "")
    {
        std::ifstream ifstrm(fileName);
        if (!ifstrm.is_open())
        {
            std::cout << "cannot open the file: " << fileName << std::endl;
            return;
        }
        else
        {
            string str;
            while (getline(ifstrm, str))
            {
                std::stringstream sstream(str);
                sstream >> command;
                if(!CommandHandler(command, sstream))
                    break;
            }
            ifstrm.close();
        }
    }
    else
    {
        std::stringstream sstream("");
        for (; ;)
        {
            cout << "> ";
            cin >> command;
            CommandHandler(command, sstream);
            if(!CommandHandler(command, sstream))
                break;
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2 && !std::ifstream(argv[1]).is_open())
        WorkWithUser();
    else
    {
        WorkWithUser(argv[1]);
    }
    return 0;
}