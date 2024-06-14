/*
Description:
Given an array of integers citations 
where citations[i] is the number of citations 
a researcher received for their ith paper, 
return the researcher's h-index.

According to the definition of h-index on Wikipedia: 
The h-index is defined as the maximum value of h 
such that the given researcher has published at least h papers 
that have each been cited at least h times.
=====
Constraints:
(1) n == citations.length   
(2) 1 <= n <= 5000
(3) 0 <= citations[i] <= 1000
=====
Example:
Input: citations = [3,0,6,1,5]
Output: 3
Explanation: 
[3,0,6,1,5] means the researcher has 5 papers in total 
and each of them had received 3, 0, 6, 1, 5 citations respectively.
Since the researcher has 3 papers with at least 3 citations each 
and the remaining two with no more than 3 citations each, their h-index is 3.
*/
#include<algorithm>
#include<iostream> 
#include<vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {

        // vector<int> records(citations.size());
        // for(int citation : citations){
        //     if(citation >= citations.size()){
        //         records.back()++;
        //     }else if(citation > 0){
        //         records[citation-1]++;
        //     }
        // }

        // int cumulation = 0;
        // int index = 0;
        // for(vector<int>::reverse_iterator i = records.rbegin(); i != records.rend(); i++){ 
        //     cumulation += *i;
        //     if(cumulation >= (citations.size()-index)){
        //         return citations.size()-index;
        //     }
        //     index++;
        // }        
        // return 0; 

        int size = citations.size();
        int index = 0;
        sort(citations.begin(), citations.end());
        for(int citation : citations){
            if(size-index <= citation){
                return size-index;
            }
            index++;
        }   
        return 0;
    }
};
int main() { 
    Solution solution;
    std::vector vector = {3,0,6,1,5};

    std::cout << solution.hIndex(vector);
    return 0; 
}