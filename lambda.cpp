//Lambda is  An anonymous function with no name
// [caputre list] (parameter) return { function body};

#include <iostream>

int main()
{
double a{10};
double b{20};

//Lambda function que usa variables fuera de ella. Trabaja con copias, por lo tanto noa fecta la variale de fuera
// a menos que se ande con referncia usando &
auto func = [a,b]()
{
    std::cout << a + b << std::endl;
};

func();

return 0;
}