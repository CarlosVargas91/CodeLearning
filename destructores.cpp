#include <iostream>

class Dog
{
    public:
        Dog() = default;
        Dog(std::string_view name_param, std::string_view breed_param, int age_param);
        ~Dog();

    // Setter
    Dog * setName (std::string_view name)
    {
        //name = name; // No sabe si el parametro o la variable
        this->name = name; // Forma correcta
        return this; // Regresa el address del objeto, satisface el return
    }
    Dog * setBreed (std::string_view breed)
    {
        
        this->breed = breed; // Forma correcta
        return this; // Regresa el address del objeto, satisface el return
    }
    private:
        std::string_view name;
        std::string_view breed;
        int * age{nullptr};
};
Dog::Dog(std::string_view name_param, std::string_view breed_param, int age_param)
{
    name = name_param;
    breed = breed_param;
    age = new int;
    *age = age_param;
    std::cout << this << std::endl; // print address of object to contruct
}

Dog::~Dog()
{
    delete age;
    std::cout << this << std::endl; // print address of object to destroy
}

void some_func()
{
    Dog * pDog = new Dog("Goyii", "Piscuis", 5); // Calls a constructor but no destructor

    delete pDog; // Call destructor
}

int main3()
{
    Dog dog2("Spot", "Cagon", 9);
    dog2.setName("Perron")->setBreed("Surron"); //COmo el return es aun pauntadoe de Objeto, se puede seguir haciendo llamados de funciones.Tambien se puede hacer por referenceia usando &

    return 0;
}