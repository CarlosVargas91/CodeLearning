#include <iostream>
using namespace std;
// Polymorfism by lvalue(locator value) or rvalue can be done
//lvalue object whom whas an address
//rvalue object who does not occupied location in memory
//Example:
int i = 10;
//But this is not:
int i;
10 = i; //10 has not location in memory

void f(int &i)
{
    cout << "lvalue reference: " << i << endl;
}

void f(int &&i)
{
    cout << "rvalue reference: " << i << endl;
}

int A()
{
    return 2;
}

void manin()
{
    int &&ref = 99;
    int &ref = 99; // does not work

    int x = 2;
    int &refe = x; // works

    int i = 10;
    f(i);       // lvalue reference
    f(99);      // rvalue reference
    f(move(i)); // rvalue reference

    // build temporary object
    const int &val = A(); //needs to be const

    const int&& valr = A();
}
