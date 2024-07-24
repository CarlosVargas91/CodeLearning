#include <iostream>
#include <vector>
#include "PrintVector.hpp"
using namespace std;

class Solution{
public:
    int RemoveElement(vector<int>& nums, int val){
        // int ctr = 0;
        // for (int i = 0; i< nums.size(); i++){
        //     if (nums[i] != val){
        //         nums[ctr] = nums[i];
        //         ctr++;
        //     }
        // }

        // VectorPrint::Printer(nums);

        // return ctr;

        int j = 1;
        for (int i = 1; i < nums.size(); i++) {
            VectorPrint::Printer(nums);
            cout << "Number j is " << j << endl;
            cout << "Number i is " << i << endl;
            if (j == 1 || nums[i] != nums[j - 2]) {
                nums[j++] = nums[i];
            } 
        }
        return j;
    }
};

int main ()
{
    Solution sol;
    vector<int> vec1 ={1,1,1,2,2,3};
    vector<int> vec2 ={0,0,1,1,1,1,2,3,3};

    cout << sol.RemoveElement(vec1, 3) << endl;
    cout << sol.RemoveElement(vec2, 2) << endl;
}