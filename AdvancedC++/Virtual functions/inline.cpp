#include <iostream>
using namespace std;

class A
{

public:
    virtual void s()
    {
        cout << "We are in the function of base class" << endl;
    }
};

class B : public A
{
public:
    // virtual void s()
    void s() // Is not needed to specify virtual as it is already in base virtual
    {
        cout << "We are in the function of derived class" << endl;
    }
};

int main()
{
    A a;
    B b;

    A *ptr = &b;

    a.s();    // inline base class
    ptr->s(); // derived class

    return 0;
}