// Virtual functions:
// Is a class member function wher is expected to be redefined in derived classes
// MUst be a member of some class
// Cannot have static members
// They are accesed by pointer
// Can be friend of another class
// Must be defined in base class
// All functions must be identical
// Cannot have a virtual constructor

#include <iostream>
using namespace std;

class A
{
public:
    virtual void display()
    {
        cout << "This is the base class" << endl;
    }

    virtual void s(int a = 0)
    {
        cout << "This is the base class" << endl;
    }
};

class B : public A
{
public:
    void display()
    {
        cout << "This is the derived class" << endl;
    }

    virtual void s(/*int a*/ int a =2)
    {
        cout << "This is the derived class" << endl;
    }
};

int main()
{
    A *a; // Pointer to base class
    B b;  // Object for B class

    a = &b; // Point to derived class

    a->display(); // Late binding

    a->s(); //Calls derive class cause it has no argument and uses default value of base fucntion

    a->s(2); // Calls derived with 2 value

    return 0;
}