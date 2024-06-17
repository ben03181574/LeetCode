/*
Description:
There are n gas stations along a circular route, 
where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank 
and it costs cost[i] of gas to travel from 
the ith station to its next (i + 1)th station. 
You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, 
return the starting gas station's index 
if you can travel around the circuit once in the clockwise direction, 
otherwise return -1. If there exists a solution, 
it is guaranteed to be unique
=====
Constraints:
(1) n == gas.length == cost.length
(2) 1 <= n <= 10^5
(3) 0 <= gas[i], cost[i] <= 10^4
=====
Example:
Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. 
Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. 
Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
*/
#include<iostream> 
#include<vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        int gasIndex = -1;
        int borrowedGas = 0;
        int leftGas = 0;
        int neededGas;
        
        for(int i = 0; i < size; i++){
            neededGas = gas[i] - cost[i];
            if(leftGas + neededGas < 0){
                gasIndex = -1;
                borrowedGas += leftGas;
                borrowedGas += neededGas;
                leftGas = 0;
            }else{
                gasIndex = (gasIndex == -1) ? i : gasIndex;
                leftGas += neededGas;
            }
        }
        
        return ((leftGas + borrowedGas) >= 0) ? gasIndex : -1;
    }
};
int main() { 
    Solution solution;
    vector<int> gas  = {3,4,5,6,8,3,70};
    vector<int> cost = {4,5,6,7,7,6,4};

    cout << solution.canCompleteCircuit(gas, cost);
    return 0; 
}