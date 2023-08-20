#include<iostream> 
#include<vector>
#include<algorithm>
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        
        
        for(int i = 0; i < nums.size(); i++){
            std::vector<int>::iterator it = std::find(nums.begin(), nums.end(), target-nums[i]);
            if(it!=nums.end() && std::distance(nums.begin(), it)!=i){
                std::vector<int> ans;
                ans.push_back(i);
                ans.push_back(std::distance(nums.begin(), it));
                return ans;
            }
        } 
        return {-1,-1};

    }
};

int main() { 
    Solution solution;
    std::vector vector = {2,7,11,5};
    for(auto n : solution.twoSum(vector,9)) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    return 0; 
}