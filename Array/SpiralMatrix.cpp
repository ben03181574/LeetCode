/*
Description:
Given an m x n matrix, return all elements of the matrix in spiral order.
=====
Constraints:
(1) m == matrix.length
(2) n == matrix[i].length
(3) 1 <= m, n <= 10
(4) -100 <= matrix[i][j] <= 100
=====
Example 1:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/
#include<iostream> 
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i = 0;
        int j = 0;
        int ccnt = i;
        int rcnt = j;
        int csize = matrix.size();
        int rsize = matrix[0].size();
        vector<int> answer;
        
        while(rcnt<rsize/2 && ccnt<csize/2){
            // push in
            while(j < rsize-rcnt-1){
                answer.push_back(matrix[i][j]);
                j++;
            }

            // push in
            while(i < csize-ccnt-1){
                answer.push_back(matrix[i][j]);
                i++;
            }

            // push in
            while(j > rcnt){
                answer.push_back(matrix[i][j]);
                j--;
            }

            // push in
            while(i > ccnt){
                answer.push_back(matrix[i][j]);
                i--;
            }

            // update
            i++;
            j++;
            ccnt = i;
            rcnt = j;
        }

        if(rcnt >= rsize/2 && rsize%2 != 0){
            // push in
            while(i < csize-ccnt){
                answer.push_back(matrix[i][j]);
                i++;
            }
        }else if(ccnt >= csize/2 && csize%2 != 0){
            // push in
            while(j < rsize-rcnt){
                answer.push_back(matrix[i][j]);
                j++;
            }
        }

        return answer;
    }
};
int main() { 
    Solution solution;
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    vector<int> answer = solution.spiralOrder(matrix);

    for(int i=0;i<answer.size();i++){
        cout << answer[i] << endl;
    }
    return 0; 
}