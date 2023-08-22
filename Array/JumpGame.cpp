/*
Description:
You are given an integer array nums. You are initially positioned at the array's first index, 
and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.
=====
Constraints:
(1) 1 <= nums.length <= 10^4
(2) 0 <= nums[i] <= 10^5
=====
Example:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/
#include<iostream> 
#include<vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {

        vector<bool> memo(nums.size(), true);
        return canJump2(nums, 0, memo);
    }
    bool canJump2(vector<int>& nums, int start, vector<bool>& memo){

        int maxJump = nums[start];
        if(maxJump >= nums.size()-1-start){
            return true;
        }else if(maxJump==0){
            return false;
        }else{
            for(int i=1; i<=maxJump; i++){
                if(!memo[start+i]){
                    continue;
                }else if(canJump2(nums, start+i, memo)){
                    return true;
                }else{
                    memo[start+i] = false;
                }
            }
            return false;
        }
    }
};

int main() { 
    Solution solution;
    std::vector vector = {2,0,6,9,8,4,5,0,8,9,1,2,9,6,8,8,0,6,3,1,2,2,1,2,6,5,3,1,2,2,6,4,2,4,3,0,0,0,3,8,2,4,0,1,2,0,1,4,6,5,8,0,7,9,3,4,6,6,5,8,9,3,4,3,7,0,4,9,0,9,8,4,3,0,7,7,1,9,1,9,4,9,0,1,9,5,7,7,1,5,8,2,8,2,6,8,2,2,7,5,1,7,9,6};

    std::cout << solution.canJump(vector);
    return 0; 
}