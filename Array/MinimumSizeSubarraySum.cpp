/*
Description:
Given an array of positive integers nums and a positive integer target, 
return the minimal length of a subarray whose sum is greater than or equal to target.
If there is no such subarray, return 0 instead.
=====
Constraints:
(1) 1 <= target <= 10^9
(2) 1 <= nums.length <= 10^5
(3) 1 <= nums[i] <= 10^4
=====
Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
*/
#include<iostream> 
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        // T：O(n)
        int left = 0;
        int right = 0;
        int size = 0;
        int total = nums[0];

        while(right!=nums.size()-1 || total>=target){
            if(total < target){
                right++;
                total += nums[right];
            }else{
                if(size > right-left+1 || size == 0){
                    size = right-left+1;
                }
                total -= nums[left];
                left++;
            }
        }
        return size;

        // T：O(nlogn)
        // int left = 1;
        // int right = nums.size();
        // int wds = (right+left)/2;
        // bool flag = false;
        
        
        // while(left <= right){
        //     int sum = 0;
        //     for(int i = 0; i <= nums.size()-wds; i++){
        //         if(i == 0){
        //             for(int j = 0; j < wds; j++){
        //                 sum += nums[j];
        //             }
        //         }else{
        //             sum -= nums[i-1];
        //             sum += nums[i+wds-1];
        //         }
        //         if(sum >= target){
        //             right = wds-1;
        //             wds = (right+left)/2;
        //             break;
        //         }else if(i == nums.size()-wds){
        //             left = wds+1;
        //             wds = (right+left)/2;
        //             break;
        //         }
        //     }
        // }
        // return (wds + 1 > nums.size())? 0 : wds+1;
    }
};
int main() { 
    Solution solution;
    std::vector vector = {2,3,1,2,4,3};
    int target = 7;

    std::cout << solution.minSubArrayLen(target, vector);
    return 0; 
}