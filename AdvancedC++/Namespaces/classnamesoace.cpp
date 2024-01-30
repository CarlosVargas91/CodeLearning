#include <iostream>
using namespace std;

namespace W
{
    class x
    {
    public:
        void display()
        {
            cout << "inside namespace" << endl;
        }
    };

    class y;

    void display();
}

class x
{

public:
    void display()
    {
        cout << "inside namespace normal" << endl;
    }
};

class W::y
{
public:
    void display()
    {
        cout << "outside namespace normal" << endl;
    }
};

void W::display() {
    cout << "outside normal method" << endl;
}

void main()
{
    W::x obj;
    W::y objy;
    x oclass;

    obj.display();
    oclass.display();
    objy.display();
    W::display();
}
