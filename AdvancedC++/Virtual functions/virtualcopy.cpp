#include <iostream>
using namespace std;

class A
{

public:
    virtual ~A()
    {
    }
    virtual void a() = 0; // Pure virtual function
    virtual void b() = 0;

    virtual A *clone() const = 0; //virtual copy constructor
    virtual A *create() const = 0; //default constructor
};

class B : public A
{

public:
    B *clone() const;
    B *create() const;
};

B *B::clone const { return new B(*this); } //Return copy constructor
B B::create const { return new B(); } //Return default constructor

int main()
{

}