/*
Description:
According to Wikipedia's article: 
"The Game of Life, also known simply as Life, 
is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, 
where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). 
Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) 
using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

The next state is created by applying the above rules simultaneously to every cell in the current state, 
where births and deaths occur simultaneously. 

Given the current state of the m x n grid board, return the next state.
Constraints:
(1) m == board.length
(2) n == board[i].length
(3) 1 <= m, n <= 25
(4) board[i][j] is 0 or 1.
=====
Example 1:
Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
*/
#include<iostream> 
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int env = 0;
        int d1s = board.size();
        int d2s = board[0].size();

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                env = 0;
                // cal each cell's env life
                for(int k=max(i-1,0); k<min(i+2,d1s);k++){
                    for(int l=max(j-1,0); l<min(j+2, d2s);l++){
                        if(i==k && j==l){
                            continue;
                        }
                        env += board[k][l]%2;
                    }    
                }
                // judge and update
                if(board[i][j]%2 == 1){
                    // live
                    if(env!=2 && env!=3){
                        // next generation will died
                        board[i][j] = board[i][j]%2+2;
                    }  
                }else{
                    // died
                    if(env == 3){
                        // next generation will live
                        board[i][j] = board[i][j]%2+2;
                    }  
                }
            }
        }

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]%2 == 1){
                    // live
                    if(board[i][j] > 1){
                        board[i][j] = 0;
                    }
                }else{
                    // died
                    if(board[i][j] > 0){
                        board[i][j] = 1;
                    }
                }
            }
        }
    }
};
int main() { 
    Solution solution;
    vector<vector<int>> matrix = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};

    solution.gameOfLife(matrix);

    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            cout << matrix[i][j];
        }
        cout << endl;
    }
    return 0; 
}