#include <iostream>
#include <vector>
#include "PrintVector.hpp"
using namespace std;


class Solution{

public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0; i<n; i++){
            nums1[m+i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());

        VectorPrint::Printer(nums1);
    }
};

int main() {
    Solution sol;

    vector<int> vec1 ={1,2,3,0,0,0};
    vector<int> vec2 ={2,5,6};

    sol.merge(vec1, 3, vec2, 3);
}