/*
Description:
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
=====
Constraints:
(1) 1 <= nums.length <= 10^5
(2) -2^31 <= nums[i] <= 2^31 - 1
(3) 0 <= k <= 10^5
=====
Example:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
*/
#include<iostream> 
#include<vector>
#include <numeric>
class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {

        k = k%nums.size();
        int buffer_index = 0;
        int buffer_prev = nums[buffer_index];
        int buffer_next = 0;
        int gcd = std::gcd(nums.size(), k);

        if(k==0){
            return;
        }else if(gcd!=1){// whether have GCD or not
            for(int i=0; i<gcd; i++){// repeat GCD times
                for(int j=0; j<nums.size()/gcd; j++){// repeat SIZE/GCD times
                    buffer_next = buffer_prev;
                    buffer_index = (buffer_index+k)%nums.size();
                    buffer_prev = nums[buffer_index];
                    nums[buffer_index] = buffer_next;
                }
                buffer_prev = nums[++buffer_index];
            }
        }else{
            for(int i=0; i<nums.size(); i++){
                buffer_next = buffer_prev;
                buffer_index = (buffer_index+k)%nums.size();
                buffer_prev = nums[buffer_index];
                nums[buffer_index] = buffer_next;
            }
        }
    }
};
int main() { 
    Solution solution;
    std::vector vector = {1,2,3,4,5,6};
    solution.rotate(vector, 4);
    for(auto n : vector) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    return 0; 
}