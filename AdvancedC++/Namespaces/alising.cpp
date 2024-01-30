#include <iostream>
using namespace std;

namespace s1
{
    namespace s2
    {
        namespace s3
        {
            namespace s4
            {
                void func()
                {
                    cout << "Inside namespace" << endl;
                }
                int x =10;
                int y =20;
                int z =30;
            }
        }
    }
}


namespace alias = s1::s2::s3::s4;

void main()
{
    s1::s2::s3::s4::func();
    alias::func();
    alias::x =6;
}