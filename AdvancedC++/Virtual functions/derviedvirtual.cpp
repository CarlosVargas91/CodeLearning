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
    //virtual void s()
    void s() // Is not needed to specify virtual as it is already in base virtual
    {
        cout << "We are in the function of derived class" << endl;
    }

    void virtual sa()
    {
        cout << "We are in the function sa of derived class" << endl;
    }
};

int main()
{
    A *a1, *a2;
    A a3;
    B b;

    a1 = &a3;
    a2 = &b;

    a1->s(); //Calls the base function
    a2->s(); //Calls the dervied function
    // a2.sa(); Does not work because is not a virtaul function
}