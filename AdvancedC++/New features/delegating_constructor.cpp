#include <iostream>
using namespace std;

class A
{
public:
    A() 
    {
        //code 1
    }

    A(int a) : A() // changed to the contructor with no argument
    {
        //code 1 in delegating contructor
        //code 2
    }

};

void manin()
{
}