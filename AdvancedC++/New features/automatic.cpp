#include <iostream>
using namespace std;
// auto dedudes type like the templates, checking for the value assigned
// decltype follows standar. Size of operator, etc

int a()
{
    return 2;
}

char b()
{
    return 'g';
}

//auto declytpe
template <class A, class B>
auto min(A a, B b) -> decltype(a < b ? a : b)
{
    return (a, b) ? a : b;
}

void main()
{
    auto x = 1;
    auto y = 2;
    auto ptr = &x; // pointer to x

    cout << typeid(x).name() << endl;   // i (int)
    cout << typeid(ptr).name() << endl; // pi (pointer int)

    decltype(a()) w;
    decltype(b()) z;

    cout << typeid(w).name() << endl; // i
    cout << typeid(z).name() << endl; // c

    cout << min(3, 4.5) << endl;
}