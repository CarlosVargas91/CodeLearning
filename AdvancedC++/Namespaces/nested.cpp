#include <iostream>
using namespace std;

namespace s1
{
    void func()
    {
        cout << "Outsoide namespace" << endl;
    }

    namespace s2
    {

        void func()
        {
            cout << "Inside namespace " << endl;
        }
    }
}

//using namespace s1; //Outisde
using namespace s1::s2; //Inside
void main()
{
    func();
}