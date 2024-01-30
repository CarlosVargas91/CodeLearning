#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
using namespace std;

//Use a class factory to call the static method and construct the object needed

class Point
{
    // use a factory method
    Point(float x, float y) : x(x), y(y) {}

public:
    float x, y;

    friend class PointFactory;
};

class PointFactory
{
public:
    static Point NewCartesian(float x, float y)
    {
        return Point{x, y};
    }

    static Point NewPolar(float r, float theta)
    {
        return Point{r * cos(theta), r * sin(theta)};
    }
};

void main()
{
    // will not work
    // Point p{ 1,2 };

    auto p = PointFactory::NewPolar(5, M_PI_4);
    cout << p << endl;
}