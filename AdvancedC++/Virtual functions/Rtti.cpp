#include <iostream>
using namespace std;

class A
{

public:
    virtual void function()
    {
    }
};

class B : public A
{
public:
};

int main()
{
    A *a = new B;
    B *b = dynamic_cast<B *>(a); // Cannot be done unless there is a virtual function

    if (b != NULL)
    {
        // is working
    }
    else
    {
        // Upcasting base to derive cannot be done
    }
}