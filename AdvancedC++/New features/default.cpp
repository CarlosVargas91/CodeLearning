#include <iostream>
using namespace std;

class A
{
public:
    A(int a)
    {
    }

    A() = default; // Constructor by default. Create explicityly the default constructor
};

class B
{
public:
    B(int a)
    {
    }

    B(double ) = delete; //DIsable convertion of types. Will convert just double to int

    B& operator = (const B&) = delete; //Disable copy assignment operator

    B(const B&) = delete; //Disable copy contructor
};
void main()
{
    A a;
    B b(10);   // Correct
    B c(3.14); // Converted to int
    b = c; //Convertion

    B b2 = b;
}