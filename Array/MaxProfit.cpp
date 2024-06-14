/*
Description:
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0
=====
Constraints:
(1) 1 <= prices.length <= 10^5
(2) 0 <= prices[i] <= 10^4
=====
Example:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxProfit = 0;
        int buyId = 0;
        int sellId = 0;
        for(sellId = buyId+1; sellId<prices.size(); sellId++){
            buyId = (prices.at(sellId) > prices.at(buyId))?buyId:sellId;
            maxProfit = max(maxProfit, prices.at(sellId)-prices.at(buyId));
        }
        return maxProfit;
    }
};
int main(){
    Solution solution;
    vector<int> prices = {7,1,5,3,6,4};
    cout << solution.maxProfit(prices) <<endl;
}