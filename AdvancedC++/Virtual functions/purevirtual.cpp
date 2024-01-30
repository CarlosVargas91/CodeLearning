#include <iostream>
using namespace std;

class A
{

public:
    virtual void s() = 0;
};

class B : public A
{
public:
    void s() // Is not needed to specify virtual as it is already in base virtual
    {
        cout << "We are in the function of derived class" << endl;
    }
};

class Base
{
public:
    virtual void func() = 0;
};

// Outside the base class and derived class
void Base::func()
{
    cout << "Pure virtual definition" << endl;
}

class derived : public Base
{
public:
    void func()
    {
        cout << "We are in the function of derived class" << endl;
    }
};

int main()
{
    // A a; Cannot create an object because is an abstract class
    B b;

    A *ptr = &b;

    ptr->s(); // derived class

    return 0;
}