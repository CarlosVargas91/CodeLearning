#include <iostream>
using namespace std;

void main()
{
    auto lambda = []()
    {
        cout << "Lambda expression" << endl;
    };
    lambda();

    auto lambda2 = [](int x, int y)
    {
        cout << "Lambda2 expression" << x + y << endl; // 13
    };
    lambda2(5, 8);

    auto lambda3 = [](int x, int y) -> int
    {
        cout << "Lambda3 expression" << x + y << endl; // 13

        return x + y;
    };
    cout << lambda3(6,4) << endl; //10
}

auto lambda = [](void) // Receive anything
{
    cout << "Lambda expression" << endl;
};