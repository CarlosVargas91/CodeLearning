#include <iostream>
using namespace std;

namespace W
{
    int x = 10;
}

namespace Y
{
    int x = 5;
}

void main()
{
    int x = 2;

    cout << x << endl;
    cout << W::x << endl;
    cout << Y::x << endl;
}