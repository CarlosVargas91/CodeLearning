#include <iostream>
using namespace std;

struct ObjElement
{
};

struct ObjBuilder
{
    ObjElement root;

    ObjBuilder& add_element(int a, int b) { return *this; } //Fluent interface, returns the object to iterate in the call
};

void main()
{
    ObjBuilder builder;

    builder.add_element(3,4).add_element(9,8).add_element(7,7); //Fluent interface

}