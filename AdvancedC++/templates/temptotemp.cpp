#include <iostream>
using namespace std;

// Template type parameter
template <template <typename T>
          class ContainerType>
class MyClass
{
    ContainerType<int> int Container;
    ContainerType<string>
        stringContainer;
};

void main()
{
}