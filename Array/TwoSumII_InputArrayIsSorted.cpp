/*
Description:
Given a 1-indexed array of integers numbers 
that is already sorted in non-decreasing order, 
find two numbers such that they add up to a specific target number. 
Let these two numbers be numbers[index1] and numbers[index2] 
where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, 
added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. 
You may not use the same element twice.

Your solution must use only constant extra space.
=====
Constraints:
(1) 2 <= numbers.length <= 3 * 10^4
(2) -1000 <= numbers[i] <= 1000
(3) numbers is sorted in non-decreasing order.
(4) -1000 <= target <= 1000
(5) The tests are generated such that there is exactly one solution.
=====
Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. 
Therefore, index1 = 1, index2 = 2. We return [1, 2].
Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. 
Therefore index1 = 1, index2 = 3. We return [1, 3].
Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. 
Therefore index1 = 1, index2 = 2. We return [1, 2].
*/
#include<iostream> 
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size()-1;
        while(numbers[left]+numbers[right] != target){
            if(numbers[left]+numbers[right] > target){
                right--;
            }else{
                left++;
            }
        }
        return {left+1, right+1};
    }
};
int main() { 
    Solution solution;
    vector nums = {2,7,11,15};
    int target = 9;
    
    vector<int> answer = solution.twoSum(nums, target);
    for(auto n : answer) {
        std::cout << n << " ";
    }
    return 0; 
}