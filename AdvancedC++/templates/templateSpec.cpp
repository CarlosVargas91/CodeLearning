#include <iostream>
using namespace std;

// Template type parameter
template <class T, class U, int I>
struct X
{
    void func()
    {
        cout << "Primary template " << endl;
    }
};

template <class T, int I>
struct X<T, T *, I>
{
    void func()
    {
        cout << "Partial specialization #1 template " << endl;
    }
};

template <class T, class U, int I>
struct X<T *, U, I>
{
    void func()
    {
        cout << "Partial specialization #2 template " << endl;
    }
};

template <class T>
struct X<int, T *, 10>
{
    void func()
    {
        cout << "Partial specialization #3 template " << endl;
    }
};

template <class T, class U, int I>
struct X<T, U *, I>
{
    void func()
    {
        cout << "Partial specialization #4 template " << endl;
    }
};

void main()
{
    X<int, int, 10> a;
    X<int, int *, 5> b;
    X<int *, float, 10> c;
    X<int, char *, 10> d;
    X<float, int *, 10> e;

    a.func(); //Primary
    b.func(); //1
    c.func(); //2 
    d.func(); //3
    e.func(); //4
}