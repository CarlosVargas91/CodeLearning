#include <iostream>
using namespace std;

void AddToCount()
{
    // Static variable in a function
    static int count = 0;
    count++;
}

class Item
{

public:
    Item()
    {
        cout << "holis " << endl;
    }
    ~Item()
    {
        cout << "adiolis " << endl;
    }
};

class Critter
{
public:
    static int CritterCount; // Value will stay

    static void AnnounceCount()
    {
        cout << CritterCount << endl;
    }
};

int Critter::CritterCount = 0; // Has to be init out of the class

void main()
{
    Critter::CritterCount = 15;

    AddToCount();

    {
        Item item;         // Item will be destroy at the end of the scope
        static Item item2; // It will continue existing
    }

    Critter::AnnounceCount(); //No need pf an object because it is a static function
}