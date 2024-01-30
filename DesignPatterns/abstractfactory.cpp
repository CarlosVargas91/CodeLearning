#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "AbstractFactory/HotDrinkFactory.hpp"
#include "AbstractFactory/DrinkFactory.hpp"
using namespace std;

void main()
{
    auto d = make_drink("tea");

    DrinkFactory df;
    df.make_drink("coffee");

    getchar();
}