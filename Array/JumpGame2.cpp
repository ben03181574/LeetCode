/*
Description:
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:
=====
Constraints:
0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. 
The test cases are generated such that you can reach nums[n - 1].

 
=====
Example:
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. 
Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/
#include<vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        
        int current_index = 0;
        int max_step = nums[0];
        int counter = 0;

        if(nums.size() == 1){
            return 0;
        }else if(nums.size() ==2){
            return 1;
        }else{
            while(current_index+max_step < nums.size()-1 ){
                // find max in slice
                int max = -1;
                int max_index = -1;
                for(int i=current_index+1; i<=current_index+max_step;i++){
                    if(max <= nums[i]+i){
                        max = nums[i]+i;
                        max_index = i;
                    }
                }
                // update
                current_index = max_index;
                max_step = nums[max_index];
                counter++;
            }
            counter++;
        }

        
        
        return counter;
    }
};

int main() { 
    Solution solution;
    std::vector vector = {10,9,8,7,6,5,4,3,2,1,1,0};

    std::cout << solution.jump(vector);
    return 0; 
}