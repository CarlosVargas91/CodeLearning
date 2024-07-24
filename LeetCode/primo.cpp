#include <iostream>
#include <vector>
#include "PrintVector.hpp"
using namespace std;


class Solution{

public:
    void primo(int range) {

        for(int i=0; i<=range; i++){
            if (i < 2){
                cout<< i << " No primo ";
            }
            else if (i ==2){
                cout<< i << " Primo ";
            }
            else if(i %2 == 0){
                cout<< i << " No Primo ";
            }
            else{
                cout<< i << " Primo ";
            }
            
        }

        cout<<endl;
    }

    // Mucho mejor
    void is_primo(int range){
        for(int i =0; i <= range; i++){
            if (i < 2 || (range % i == 0 && i !=2)){
                cout<< i << " No primo " << endl;
            }
            else
                cout<< i << " Primo " << endl; 
        }
    }
};

int main() {
    Solution sol;

    sol.is_primo(100);
}