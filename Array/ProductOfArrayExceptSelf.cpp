/*
Description:
Given an integer array nums, return an array answer 
such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
=====
Constraints:
(1) 2 <= nums.length <= 10^5
(2) -30 <= nums[i] <= 30
(3) The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
=====
Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
*/
#include<iostream> 
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> productVector(size, 1);
        
        for(int i = 1; i < size; i++){
            productVector[i] = productVector[i-1] * nums[i-1];
        }
        for(int i = size - 2; i >= 0; i--){
            productVector[i] *= nums[i+1];
            nums[i] *= nums[i+1];
        }
        return productVector;
    }
};
int main() { 
    Solution solution;
    vector<int> nums  = {1,2,3,4};

    nums = solution.productExceptSelf(nums);
    for(int num : nums){
        cout << num ;
    }
    cout << endl;

    return 0; 
}