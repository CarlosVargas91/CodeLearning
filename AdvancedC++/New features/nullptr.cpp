#include <iostream>
using namespace std;

int i = NULL;     // Ok
int a = nullptr;  // Not Ok
int *b = NULL;    // OK , integer is converted to ptr
int *c = nullptr; // Ok

void main()
{
}