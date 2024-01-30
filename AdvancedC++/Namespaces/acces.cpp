#include <iostream>
using namespace std;

namespace w
{
    int x = 10;

    void func()
    {
        cout << "Names pace 1" << endl;
    }
}

namespace b
{
    void func()
    {
        cout << "Names pace 2" << endl;
    }
}

using namespace b; //Use to specify which namespace
void main()
{

    cout << w::x << endl; // normal way of access

    func(); //Namespace b
}