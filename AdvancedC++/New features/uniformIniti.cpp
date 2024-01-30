#include <iostream>
#include <bits10_1.h/std++.h>

using namespace std;

class A
{
    int arr[4];

public:
    A(int x, int y, int z, int w) : arr{x, y, z, w} {} // 2 Array data member of a class init
};

class B
{
    int x;
    int y;

public:
    A(int a, int b) : x{a}, y{b} {} // 3 Implicit init of an object
};

class C
{
    int a;
    int b;

public:
    C(intx, int y) : a{x}, b{y} {}

    void print()
    {
        cout << a << b << endl;
    }
};

A f(int x, int y)
{
    return {x, y}; // Compiler knows the constructor of class B will be called
}

void f(C x)
{
    x.print();
}

void main()
{
    int *pi = new int[5]{1, 2, 3, 4}; // 1 Dynamic array init

    for (int i = 0, i < 5; i++)
    {
        cout << *(pi + i) << endl;
    }

    A a(1, 2, 3, 4);
    B b = f(1, 2); // Calls the constructor

    f{1,2}; //4 implicit  return init
}
