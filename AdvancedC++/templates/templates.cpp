#include <iostream>
using namespace std;

template <class T>
class Calculator
{
private:
    T num1, num2;

public:
    Calculator(T a, T b)
    {
        num1 = a;
        num2 = b;
    }

    void display()
    {
        cout << "The values are" << num1 << num2 << endl;
    }
};

// Non type parameter
template <int i>
class A
{
};

template <double *dp>
class B
{
};

template <void (*func)(int)>
void c()
{
}

template <class T> //<typename T> also works
T large(T n1, T n2)
{
    return (n1 > n2) ? n1 : n2;
}

// Non type parameter. Works like argument of a function
A<3> a3;
A<sizeof(string)> as;
double d;
B<&d> bpd;
B<NULL> bn;
void myfunc(int);

struct MYClass
{
    static void staticfunc();
};

template<class T>
void fsp(T a)
{
    cout << "template called" << endl;
}
// Specialized template. WIll override the function when is called with int
template <>
void fsp(int a)
{
    cout << "Specialized template for integer" << endl;
}

int main(int argc, char **argv)
{

    large<int>(4, 3);
    large<float>(3.5, 5.6);

    Calculator<int> intCalc(2, 1);
    Calculator<float> floatCalc(3.4, 7.98);

    c<&myfunc>();
    c<&MYClass::staticfunc()>;

    return 0;
}