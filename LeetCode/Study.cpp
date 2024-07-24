#include <iostream>
#include <vector>
#include <memory>
#include "PrintVector.hpp"
#include <sstream>
using namespace std;

// Study guideline

/*
En C++, los términos overload (sobrecarga) y override (sobrescritura) se refieren a dos conceptos diferentes relacionados con las funciones:

Polimorfismo estatico
Overload (Sobrecarga): La sobrecarga ocurre cuando se definen múltiples funciones con el mismo nombre pero con diferentes firmas (es decir, diferentes tipos de parámetros o número de parámetros). Esto proporciona un mejor rendimiento porque se realiza en tiempo de compilación123.
class Test {
    // Test::func está sobrecargado
    virtual void func(int x);
    virtual void func(double y);
};

Polimorfismo dinamico
Override (Sobrescritura): La sobrescritura ocurre cuando una función en una clase derivada tiene una firma idéntica a una función virtual en una clase base. Esto cambia el comportamiento de esa función en la clase derivada. En este caso, la clase base proporciona la interfaz y la clase derivada proporciona la implementación45.
class Base {
    virtual void func();
};

class Derived : public Base {
    // Derived::func sobrescribe Base::func
    void func() override;
};
*/

// Smart pointers
/* 
std::unique_ptr: Este es un smart pointer que posee y administra otro objeto a través de un puntero y lo desasigna cuando el unique_ptr sale de alcance. No se puede copiar a otro unique_ptr, pasar por valor a una función, o usar en cualquier contexto de C++ donde se requiera una copia. Sin embargo, se puede mover a otro unique_ptr de la misma clase.
std::shared_ptr: Este smart pointer mantiene un recuento de referencias a un objeto que ha asignado en el heap. El objeto se desasigna cuando el último shared_ptr que apunta a él se destruye.
std::weak_ptr: Este es un smart pointer que mantiene una referencia no propietaria (“débil”) a un objeto que es administrado por shared_ptr. No contribuye al recuento de referencias de shared_ptr. Se utiliza para prevenir referencias circulares en shared_ptr.
*/
std::unique_ptr<int> ptr1(new int(5));
std::shared_ptr<int> ptr2(new int(10));
std::weak_ptr<int> ptr3 = ptr2;

// What is dynamic allocation? Allocate objects in memory dinamyc
// How to do it?; using new keyword and delete to deallocate in heap
// What is the difference between stack and heap memory?
/*

Stack Memory:
It is used for static memory allocation.
The memory is managed by CPU, and it is automatically allocated and deallocated.
It is faster to allocate compared to heap memory.
The size of the stack is set when a thread is created. If a program exceeds the stack size, it will result in a stack overflow error.
It is mainly used for function call operations and local variables.

Heap Memory:
It is used for dynamic memory allocation.
The memory needs to be manually managed. You need to allocate memory (using new in C++) when you need it and deallocate it (using delete in C++) when you don’t.
It is slower to allocate compared to stack memory.
The size of the heap is usually much larger and only limited by the size of addressable memory. If the program runs out of heap space, it will get an out of memory error.
It is used when you need variables to stay in memory for a long time, or if you need large arrays or structures.
*/

/*
A memory leak occurs in a program when the program fails to release discarded memory back to the operating system. This happens when dynamically allocated memory, typically allocated on the heap, is no longer needed by the program but isn’t deallocated.
*/
int leak() {
    int* ptr = new int(5); // memory allocated using new
    // ... some code ...
    // forgot to delete ptr
    return 0;
} // memory leak occurs here

/*
There are several ways to check for memory leaks in a program:

Manual Code Review: You can manually review your code to ensure that every allocation of memory (like new in C++) has a corresponding deallocation (delete in C++). This can be time-consuming and error-prone, especially for larger codebases.
Use of Smart Pointers in C++: In modern C++, you can use smart pointers (like std::unique_ptr and std::shared_ptr) which automatically deallocate memory when it’s no longer in use. This can help prevent memory leaks in the first place.
Profiling Tools: There are many profiling tools available that can detect memory leaks. These tools run your program and monitor memory allocation and deallocation. Some of these tools include:
Valgrind: An open-source memory debugging tool for Linux. Valgrind can detect memory leaks, uninitialized memory, and other memory-related errors.
Visual Leak Detector: A free, robust, open-source memory leak detection system for Visual C++.
AddressSanitizer: A fast memory error detector built into many compilers like GCC and Clang.
Static Analysis Tools: These tools analyze your code for potential issues, including memory leaks, without actually running the program. Examples include Cppcheck and Clang Static Analyzer.
*/

/*
A linked list is a data structure used in computer science to organize data. It consists of nodes, where each node contains a data field and a reference(link) to the next node in the sequence. This allows for efficient insertions and deletions.

There are several types of linked lists, including singly linked lists, doubly linked lists, and circular linked lists. Here’s a simple example of a singly linked list in C++:
*/
class Node {
public:
    int data;
    Node* next;
};

void printList(Node* n)
{
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}

int mainNode()
{
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    // allocate 3 nodes in the heap
    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1; // assign data in first node
    head->next = second; // Link first node with the second node

    second->data = 2; // assign data to second node
    second->next = third;

    third->data = 3; // assign data to third node
    third->next = NULL;

    printList(head);

    return 0;
}

/*
Arrays and linked lists are both data structures that can be used to store data, but they have different properties and are suited to different types of tasks. Here are some key differences:

Memory Allocation:
Array: An array is a contiguous block of memory. The size of the array is fixed at the time of creation and cannot be changed.
Linked List: A linked list is a series of nodes, each containing data and a pointer to the next node in the list. The list can easily grow and shrink in size by adding or removing nodes.
Access Time:
Array: Arrays allow constant-time access to any element (i.e., O(1) time complexity), which means you can directly access any element in the array using its index.
Linked List: Linked lists have linear access time (i.e., O(n) time complexity), which means you have to traverse the list from the start to access a particular element.
Insertions and Deletions:
Array: Inserting or deleting an element in an array requires shifting all subsequent elements, which can be costly (i.e., O(n) time complexity).
Linked List: Inserting or deleting a node in a linked list only requires updating the links of the neighboring nodes, which can be done in constant time (i.e., O(1) time complexity), provided we have a pointer to the node immediately preceding the one to be inserted or deleted.
Memory Usage:
Array: Arrays are memory-efficient because they only store the data.
Linked List: Each node in a linked list also needs to store a pointer to the next node, which increases the memory footprint.
Usage:
Array: Arrays are useful when the size of the data is known and fixed, or when you need to frequently access elements from different positions.
Linked List: Linked lists are useful when you need to frequently add or remove items from the data structure, and you don’t need to access elements by their position.
In summary, whether to use an array or a linked list depends on the specific requirements of the problem you’re trying to solve. Each has its own advantages and trade-offs.
*/

// Reversing a linked list
class Node {
public:
    int data;
    Node* next;
};

void reverseList(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;  // Store next node
        current->next = prev;  // Reverse current node's pointer
        prev = current;        // Move pointers one position ahead
        current = next;
    }
    *head = prev;
}

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

int Reversemain() {
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    cout << "Original list: ";
    printList(head);

    reverseList(&head);

    cout << "\nReversed list: ";
    printList(head);

    return 0;
}


// Espiral matrix
void printSpiral(const std::vector<std::vector<int>>& matrix) {
    if (matrix.empty()) return;

    int top = 0;
    int bottom = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;

    while (true) {
        // Print top row
        for (int i = left; i <= right; i++) {
            std::cout << matrix[top][i] << " ";
        }
        if (++top > bottom) break;

        // Print right column
        for (int i = top; i <= bottom; i++) {
            std::cout << matrix[i][right] << " ";
        }
        if (--right < left) break;

        // Print bottom row
        for (int i = right; i >= left; i--) {
            std::cout << matrix[bottom][i] << " ";
        }
        if (--bottom < top) break;

        // Print left column
        for (int i = bottom; i >= top; i--) {
            std::cout << matrix[i][left] << " ";
        }
        if (++left > right) break;
    }
}

int main() {
    std::vector<std::vector<int>> matrix = {{1, 2, 3, 4},
                                             {5, 6, 7, 8},
                                             {9, 10, 11, 12},
                                             {13, 14, 15, 16}};
    printSpiral(matrix);
    return 0;
}

// Palindrome function
bool isPalindrome(const std::string& str) {
    std::string copy = str;
    std::reverse(copy.begin(), copy.end());
    return str == copy;
}

int main() {
    std::string str = "madam";
    if (isPalindrome(str)) {
        std::cout << str << " is a palindrome" << std::endl;
    } else {
        std::cout << str << " is not a palindrome" << std::endl;
    }
    return 0;
}

//SOLID
/*
SOLID principles are a set of guidelines or best practices for object-oriented programming that help to create software that is more maintainable, flexible, and scalable. The term “SOLID” is an acronym for five different principles, each of which focuses on a different aspect of software development:

S — Single Responsibility Principle (SRP)
O — Open-Closed Principle (OCP)
L — Liskov Substitution Principle (LSP)
I — Interface Segregation Principle (ISP)
D — Dependency Inversion Principle (DIP)

S - It states that a class should have only one responsibility, which means it should have only one reason to change. 
O - It states that a class should be open for extension but closed for modification. This principle helps in making the code more maintainable and flexible.
L - It states that objects of a superclass should be able to be replaced with objects of a subclass without affecting the correctness of the program. In other words, a subclass should be able to be substituted for its parent class without causing any errors or unexpected behavior.
Virtual and override
I - It states that a client should not be forced to depend on interfaces that it does not use. In other words, a class should not have to implement methods that it does not need.
D - It states that high-level modules should not depend on low-level modules. Both should depend on abstractions. Abstractions should not depend on details. Details should depend on abstractions.
*/

/*
int * const ptr;  //Direccion constante pero valor variable
const int * ptr;  //Valor constante pero direccion variable 


valor        |  direccion
-------------|------------
const int *    const ptr; 
 
 this : apuntador al objeto (referencia)
 Destructor: SOlo uno por clase
 Protected: Hace publico los elementos a las clases derivadas
 private; Privado para todo
 
 valor direccion puntero;
 
 Un elemtno static d euna clase debe ser inicializada fuera de esta, ya que es una clase. Es decir no esta definidia como instancia de la clase
 Si no como una clase nueva. Esto hace que se mantenga su valor aun cuando el scope de la clase termino.
 
 Constructor no puede ser virtual. Destructor si
 
 unique_ptr: no se puede copiar
 shared_ptr: si se puede cipiar y tiene un contador de referencia
 weak_ptr: como el shared pero no tiene un contador de referencia
 
 virtual table es un apuntador almacenado en memoria
 concepts son restricciones para forzar usar un tipo de dato en templates
 
 En C++, cuando se crea un objeto de una clase derivada, primero se ejecuta el constructor de la clase base y luego se ejecuta el constructor de la clase derivada1. Esto se debe a que la clase derivada puede depender de los miembros de la clase base, por lo que estos deben ser inicializados primero1.

Por otro lado, los destructores se llaman en el orden inverso en el que se llamaron sus constructores correspondientes1. Esto significa que primero se ejecuta el destructor de la clase derivada y luego se ejecutan los destructores de las clases base1. La razón de esto es que la clase derivada puede depender de los miembros de la clase base, por lo que estos no deben ser destruidos hasta que la clase derivada haya terminado de usarlos

Singleton:
Constructor privado
Delete constructor copiar
Una instancia static

Compiler makes the funciton depending of template needed


vector: usually implemented as an array
good at: indexing, appending at the end
not good at: inserting somewhere, even not at the front
cost per element: sizeof(element)
list: double linked list
good at: inserting anywhere
not good at: unable to index
cost per element: sizeof(element)+N
deque: often implemented as array of arrays
good at: adding at begin and end
not good at: inserting at other places
cost per element: sizeof(element)+Nelem/M
set, map: implementation often as binairy tree or red/black tree
good at: sorted storage, access by key
not good at: sequential access
cost per element: sizeof(element)+N
unordered set,map: implementation as hashes 11

join en thread es cuando termina el thread

unorderedmap : No repite keys, quiere decir que en problemas de eliminar valores duplicados, este funciona bien
*/
// Start in python for ASML 
// for line in (stdin, "")

/*
def fizzbuzz(A, B, N):
    # Si N es divisible por A y B, imprime "FizzBuzz"
    if N % A == 0 and N % B == 0:
        print("FizzBuzz")
    # Si N es divisible por A, imprime "Fizz"
    elif N % A == 0:
        print("Fizz")
    # Si N es divisible por B, imprime "Buzz"
    elif N % B == 0:
        print("Buzz")
    # De lo contrario, imprime N
    else:
        print(N)

# Lee la entrada desde stdin
for line in sys.stdin:
    # Convierte la cadena de entrada en una lista de enteros
    A, B, N = map(int, line.strip().split())
    # Llama a la función con los números A, B y N
    fizzbuzz(A, B, N)

En C++ */
int main() {
    std::string line;
    // Lee una línea de la entrada estándar
    while (std::getline(std::cin, line)) {
        int A, B, N;
        std::istringstream iss(line);
        // Convierte la cadena de entrada en una lista de enteros
        iss >> A >> B >> N;
        // Ahora puedes usar A, B y N en tu código
    }
    return 0;
}


int main() {
    std::string str = "123 456";
    
    // Usando istringstream para leer de un string
    std::istringstream iss(str);
    int a, b;
    iss >> a >> b;
    std::cout << "a: " << a << ", b: " << b << std::endl;  // Salida: a: 123, b: 456

    // Usando stringstream para leer de un string y escribir en un string
    std::stringstream ss;
    ss << a << b;
    std::string str2 = ss.str();
    std::cout << "str2: " << str2 << std::endl;  // Salida: str2: 123456

    return 0;
}

/*
 Funciones básicas para trabajar con cadenas C++:

strlen(cadena): Obtiene la longitud de la cadena (sin contar el carácter nulo).
strcat(destino, origen): Concatena la cadena origen al final de la cadena destino.
strcpy(destino, origen): Copia la cadena origen en la cadena destino.
strcmp(cadena1, cadena2): Compara dos cadenas y devuelve un valor que indica si son iguales, menores o mayores1.

La biblioteca string: C++ ofrece una biblioteca estándar llamada string que proporciona una forma más moderna y segura de trabajar con cadenas. Esta biblioteca ofrece una amplia gama de funciones para manipular cadenas, como:

size(): Obtiene la longitud de la cadena.
append(cadena): Concatena una cadena al final de la otra.
compare(cadena): Compara dos cadenas y devuelve un valor que indica si son iguales, menores o mayores.
find(subcadena): Busca la primera aparición de una subcadena dentro de otra
*/
/*
String Python

Funciones básicas para trabajar con cadenas:

len(cadena): Obtiene la longitud de la cadena.
cadena1 + cadena2: Concatena la cadena1 con la cadena2.
cadena.upper(): Convierte todos los caracteres de la cadena a mayúsculas.
cadena.lower(): Convierte todos los caracteres de la cadena a minúsculas.
cadena.replace(viejo, nuevo): Reemplaza todas las ocurrencias del substring viejo con el substring nuevo en la cadena1.
3. Ejemplos prácticos de uso de cadenas:

Python

# Imprimir un mensaje en pantalla
print("Hola mundo!")

# Concatenar dos nombres para formar un saludo
nombre1 = "Juan"
nombre2 = "Pérez"
saludo = nombre1 + " " + nombre2
print("Hola, " + saludo)

# Convertir una cadena a mayúsculas
nombre = "juan"
nombre_mayusculas = nombre.upper()
print(nombre_mayusculas)
Código generado por IA. Revisar y usar cuidadosamente. Más información sobre preguntas frecuentes.
4. La función split: La función split divide una cadena en una lista donde cada palabra es un elemento de la lista. Por defecto, split usa espacios en blanco como delimitador1.

5. Ejemplo de uso de la función split:

Python

texto = "Hola mundo, esto es Python"
palabras = texto.split()
print(palabras)  # Imprime ['Hola', 'mundo,', 'esto', 'es', 'Python']
Código generado por IA. Revisar y usar cuidadosamente. Más información sobre preguntas frecuentes.
6. Formateo de cadenas: Python ofrece varias formas de formatear cadenas, incluyendo el método format y las f-strings (introducidas en Python 3.6). Aquí tienes un ejemplo de cada uno1:

Python

# Usando el método format
nombre = "Juan"
edad = 30
print("Mi nombre es {} y tengo {} años".format(nombre, edad))

# Usando f-strings
nombre = "Juan"
edad = 30
print(f"Mi nombre es {nombre} y tengo {edad} años")
*/


// Leetcode keys
#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec;

    // Añadir elementos
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    // Acceder a elementos
    std::cout << "Primer elemento: " << vec.front() << std::endl;
    std::cout << "Último elemento: " << vec.back() << std::endl;
    std::cout << "Segundo elemento: " << vec.at(1) << std::endl;

    // Tamaño del vector
    std::cout << "Tamaño: " << vec.size() << std::endl;

    // Eliminar el último elemento
    vec.pop_back();

    // Comprobar si el vector está vacío
    if (!vec.empty()) {
        std::cout << "El vector no está vacío" << std::endl;
    }

    // Iterar sobre el vector
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}

#include <unordered_map>
#include <iostream>

int main() {
    std::unordered_map<std::string, int> map;

    // Insertar elementos
    map["uno"] = 1;
    map.insert(std::make_pair("dos", 2));

    // Acceder a elementos
    std::cout << "uno: " << map["uno"] << std::endl;
    std::cout << "dos: " << map["dos"] << std::endl;

    // Tamaño del mapa
    std::cout << "Tamaño: " << map.size() << std::endl;

    // Buscar una clave
    if (map.find("tres") == map.end()) {
        std::cout << "La clave 'tres' no se encuentra en el mapa" << std::endl;
    }

    // Eliminar un elemento
    map.erase("uno");

    // Comprobar si el mapa está vacío
    if (!map.empty()) {
        std::cout << "El mapa no está vacío" << std::endl;
    }

    // Iterar sobre el mapa
    for (auto it = map.begin(); it != map.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    return 0;
}
