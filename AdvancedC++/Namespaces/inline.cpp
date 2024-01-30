#include <iostream>
using namespace std;

namespace s1
{
    inline namespace s2
    {
        inline namespace s3
        {
            int x = 10;
        }
    }
}

using namespace s1;
void main()
{
    cout << s1::x << endl; // It works because s2 is inline. Is treated as if it is a member of s1 namespace

    cout << x << endl; // It works because s2 is inline. Is treated as if it is a member of s1 namespace
}