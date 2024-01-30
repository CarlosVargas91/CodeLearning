#include <iostream>
using namespace std;

class A
{

private:
    virtual void function()
    {
    }

    friend int main(); //To call a private method
};

class B : public A
{
public:
    void function()
    {
    }
};

int main()
{
    A *a = new B;
    a->function();

    return 0;
}