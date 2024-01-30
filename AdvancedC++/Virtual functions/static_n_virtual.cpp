#include <iostream>
using namespace std;

class A
{
public:
    virtual static void s()
    {
    }
};

class B : public A
{
public:
    static void s()
    {
    }
};

int main()
{
    A *a;
    B b;

    a = &b;
    a->s();
}