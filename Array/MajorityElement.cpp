/*
Description:
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. 
You may assume that the majority element always exists in the array.
=====
Constraints:
(1) n == nums.length
(2) 1 <= n <= 5 * 10^4
(3) -10^9 <= nums[i] <= 10^9
=====
Example:
Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/
#include<iostream> 
#include<vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0];
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(count==0) ans = nums.at(i);
            count += (ans==nums.at(i))?1:-1;
        } 
        return ans;
    }
};
int main() { 
    Solution solution;
    std::vector vector = {1,3,1,4,1};

    std::cout << solution.majorityElement(vector);
    return 0; 
}