#include <iostream>
#include <vector>
#include "PrintVector.hpp"
#include <unordered_map>
using namespace std;


class Solution{

public:
    int Majority(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int, int> m;

        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }

        for (auto x: m){
            cout << "Clave "<< x.first << "Valor" << x.second<< endl;
        }
        n = n/2;

        for (auto x: m){
            if(x.second > n)
                return x.first;
        }
        return 0;
    }
};

int main() {
    Solution sol;

    vector<int> vec1 ={3,2,3};
    vector<int> vec2 ={2,2,1,1,1,2,2};

    cout << sol.Majority(vec1) << endl;
    cout << sol.Majority(vec2) << endl;
}