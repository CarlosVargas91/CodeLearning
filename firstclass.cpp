#include <iostream>

const double PI{3.1416};

class Cylinder
{
    public:
    //Constructor
    //Cylynder() = default;
    Cylinder()
    {
        BaseRatio = 3.0;
        height = 56.5;
    }

    Cylinder(double radParam, double heightParam)
    {
        BaseRatio = radParam;
        height = heightParam;
    }

    double volume()
    {
        return PI * BaseRatio * height;
    }

private:
    double BaseRatio{4};
    double height{3};
};



// int main3()
// {
//     Cylinder cyl1(10,56);

//     //Pointer to object in stack
//     Cylinder *p_cyl = &cyl1;

//     //Pointer dynamic in the heap
//     Cylinder *P_cylHeap = new Cylinder(45,3);
    
//     std::cout << cyl1.volume() << std::endl;

//     std::cout << p_cyl->volume() << std::endl;

//     std::cout << P_cylHeap->volume() << std::endl;
    
//     //Delete pointer object to release memory
//     delete P_cylHeap;
    
//     return 0;
// }