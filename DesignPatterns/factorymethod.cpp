#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
using namespace std;

// Private constructor and use of static method to construct different type of objects

class Point
{

private:
    Point(float x, float y) : x(x), y(y) {}

public:
    float x, y;

    static Point NewCartesian(float x, float y)
    {
        return {x, y};
    }

    static Point NewPolar(float r, float theta)
    {
        return {r * cos(theta), r * sin(theta)};
    }
};

void main()
{
    // will not work
  //Point p{ 1,2 };

  auto p = Point::NewPolar(5, M_PI_4);
  cout << p << endl;
}