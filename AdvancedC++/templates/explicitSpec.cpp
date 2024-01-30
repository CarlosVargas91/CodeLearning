#include <iostream>
using namespace std;

template <class T = float, int i = 5>
class A
{
    A();
    int value;
};

// spec temp
template <>
class A<>
{
public:
    A();
};

template <>
class A<double, 10>
{
public:
    A();
};

template <class T, int i>
A<T, i>::A() : value(i) // Using value from primary template class
{
    cout << "Primary template" << value << endl;
}

A<>::A(){
    cout <<"Explicit specialization" <<endl;
}

// COnstructor line 23
A<double,10>::A(){
    cout <<"Explicit specialization <double, 10>" <<endl;
}

void main()
{
    A<int, 8> x; //Primary template
    A<> y; //Explicit
    A<double,10> z; //Explicit double,10
}