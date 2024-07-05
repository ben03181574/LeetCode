/*
Description:
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
DO NOT allocate another 2D matrix and do the rotation.
=====
Constraints:
(1) n == matrix.length == matrix[i].length
(2) 1 <= n <= 20
(3) -1000 <= matrix[i][j] <= 1000
=====
Example 1:
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
*/
#include<iostream> 
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0; i<matrix.size(); i++){
            for(int j=i; j<matrix[0].size(); j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size()/2; j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][matrix[i].size()-1-j];
                matrix[i][matrix[i].size()-1-j] = tmp;
            }
        }
    }
};
int main() { 
    Solution solution;
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};

    solution.rotate(matrix);

    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            cout << matrix[i][j];
        }
        cout << endl;
    }
    return 0; 
}