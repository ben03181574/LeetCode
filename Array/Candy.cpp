/*
Description:
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.
=====
Constraints:
(1) n == ratings.length
(2) 1 <= n <= 2 * 10^4
(3) 0 <= ratings[i] <= 2 * 10^4
=====
Example 1:

Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
Example 2:

Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.
*/
#include<iostream> 
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> records(ratings.size(), 1);
        int totalCandy = ratings.size();

        for(int i = 0; i < ratings.size() - 1; i++){
            if(ratings[i] < ratings[i+1] && records[i] >= records[i+1]){
                totalCandy += (records[i]-records[i+1]+1);
                records[i+1] += (records[i]-records[i+1]+1);
            }
        }
        for(int i = ratings.size() - 1; i > 0 ; i--){
            if(ratings[i] < ratings[i-1] && records[i] >= records[i-1]){
                totalCandy += (records[i]-records[i-1]+1);
                records[i-1] += (records[i]-records[i-1]+1);
            }
        }
        
        return totalCandy;
    }
};
int main() { 
    Solution solution;
    std::vector vector = {1,6,6,6,6,6,5,1,0,1,5,5,5,2,1};

    std::cout << solution.candy(vector);
    return 0; 
}