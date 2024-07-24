#include <iostream>
#include <vector>
#include "PrintVector.hpp"
#include <unordered_map>
using namespace std;


class Solution{

public:
    void Rotate(vector<int>& nums, int k) {

        int n = nums.size();
        k = k % n; // Ensure k is within the range [0, n)

        cout << "n is "<< n << " k is: " << k << endl;

        // Reverse the entire array
        reverse(nums.begin(), nums.end());
        
        VectorPrint::Printer(nums);

        // Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);

        VectorPrint::Printer(nums);
        
        // Reverse the rest of the elements after k
        reverse(nums.begin() + k, nums.end());

        VectorPrint::Printer(nums);
    }
};

int main() {
    Solution sol;

    vector<int> vec1 ={1,2,3,4,5,6,7};
    vector<int> vec2 ={2,2,1,1,1,2,2};

    // cout << sol.Rotate(vec1, 3) << endl;
    sol.Rotate(vec1, 3);
}