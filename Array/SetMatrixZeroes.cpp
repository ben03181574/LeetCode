/*
Description:
Given an m x n integer matrix matrix, if an element is 0, 
set its entire row and column to 0's.

You must do it in place.
=====
Constraints:
(1) m == matrix.length
(2) n == matrix[0].length
(3) 1 <= m, n <= 200
(4) -2^31 <= matrix[i][j] <= 2^31 - 1
=====
Example 1:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
*/
#include<iostream> 
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool isFirstRowZero=false;
        bool isFirstColZero=false;
        for(int i=0; i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j] == 0){
                    if(i==0){
                        isFirstRowZero = true;
                    }
                    if(j==0){
                        isFirstColZero = true;
                    }
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
    
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(isFirstColZero){
            for(int i=0;i<matrix.size();i++){
                matrix[i][0] = 0;
            }
        }
        if(isFirstRowZero){
            for(int j=0; j<matrix[0].size();j++){
                matrix[0][j] = 0;
            }
        }
    }
};
int main() { 
    Solution solution;
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};

    solution.setZeroes(matrix);

    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            cout << matrix[i][j];
        }
        cout << endl;
    }
    return 0; 
}