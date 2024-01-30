#include <iostream>
using namespace std;

template <class T>
void f(T x, T y)
{
    cout << "Template " << endl;
}

void f(int w, int f)
{
    cout << "Non Template " << endl;
}

void main()
{
    f(1, 2);  //Non template
    f('a', 'b'); //Template
    f(1, 'b'); //Non template
}