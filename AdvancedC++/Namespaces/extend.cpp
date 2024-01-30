#include <iostream>
using namespace std;
// using name twice

namespace w
{
    int x = 10;
}
// it beocmes or extends the namespace
namespace w
{
    int y = 2;
}

// Unnamed
namespace
{
    int x = 15;
}

void main()
{
    cout << w::x << w::y << endl; // 10 2
    cout << x << endl; //Unnamed
}