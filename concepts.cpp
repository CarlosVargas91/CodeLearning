#include <iostream>
#include <type_traits>
#include <concepts>

//Concepts son restricciones para forzar a usar un tipo de dato
template <std::integral T> // Forza a ser un integro el tipo T

T add (T a, T b)
{
    return a = b;
}

auto add(std::integral auto a,std::integral auto b )
{
    return a =b;
}

// Crear tu propio concept
template <typename F>
concept MyConcept = std::is_integral_v<F>;

int main2()
{



    return 0;
}