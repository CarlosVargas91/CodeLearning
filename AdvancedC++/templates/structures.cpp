#include <iostream>
using namespace std;

template <typename T>
struct link
{
    T data;
    link *next;
};

template <class T>
class linklist
{

private:
    link<T> *first; // Points to first list link

public:
    linklist()
    {
        first = NULL;
    }

    void additem(T d);
    void display();
};

template <class T>
void linklist<T>::additem(T d)
{
    link<T> *newlink = new link<T>; // New node created
    newlink->data = d;
    newlink->next = first;
    first = newlink;
}

template <class T>
void linklist<T>::display()
{
    link<T> *current = first;
    while (current != NULL)
    {
        cout << current->data, , endl;
        current = current->next;
    }
}

void main()
{
    linklist<int> li;
    li.additem(2); // Int because object was created as an integer
    li.additem(3);
    li.additem(8);
    li.additem(10);

    li.display();

    linklist<char> lc;

    li.additem('a'); // char because object was created as a char
    li.additem('b');
    li.additem('c');
    li.additem('d');

    li.display();
}