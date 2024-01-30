#include <iostream>
using namespace std;

// Helps to create an abstract class, but using the destructor as the pure virtual method
class A
{

public:
    virtual ~A() = 0;

    virtual void s() = 0; // Is not needed to provide virtual definition as in destructor
};

A::~A()
{
    //empty
}

class B : public A
{

public:
    ~B()
    {
        cout << "Destructor dereived" << endl;
    }

    void s()
    {
        
    }
};

int main()
{
    A *a;
    B b;
    a = &b;
}