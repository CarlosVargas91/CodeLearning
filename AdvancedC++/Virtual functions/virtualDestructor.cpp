#include <iostream>
using namespace std;

class A
{

public:
    virtual ~A()
    {
        cout << "Destructor base" << endl;
    }
};

class B : public A
{

public:
    ~B()
    {
        cout << "Destructor dereived" << endl;
    }
};

int main()
{
    A *a = new B; //Upcasting; Memory leak cause it does not destro derived class object
    // virtual in destructor shall be added
    delete a;
}