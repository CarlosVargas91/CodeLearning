#include <iostream>
#include <vector>
using namespace std;

class VectorPrint{
public:
    static void Printer(vector<int>& vec){
        for (int i : vec)
        {
            cout << i << " ";
        }
        cout << endl;
    }
};