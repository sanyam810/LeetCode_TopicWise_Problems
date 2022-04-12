/**

According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.

Example :

Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]

**/

class Solution {
public:
    
    int getLiveNeigh(vector<vector<int>>& temp, int i, int j, int m, int n) {
        int liveNeigh = 0;
        if(i > 0) {
            if(temp[i-1][j] == 1) {
                liveNeigh++;
            }
        } 
        
        if(i < m-1) {
            if(temp[i+1][j] == 1) {
                liveNeigh++;
            }
        } 
        
        if(j > 0) {
            if(temp[i][j-1] == 1) {
                liveNeigh++;
            }
        }
        
        if(j < n-1) {
            if(temp[i][j+1] == 1) {
                liveNeigh++;
            }
        } 
        
        if(i > 0 && j > 0) {
            if(temp[i-1][j-1] == 1) {
                liveNeigh++;
            }
        } 
        
        if(i < m-1 && j < n-1) {
            if(temp[i+1][j+1] == 1) {
                liveNeigh++;
            }
        } 
        
        if(i < m-1 && j > 0) {
            if(temp[i+1][j-1] == 1) {
                liveNeigh++;
            }
        } 
        
        if(i > 0 && j < n-1) {
            if(temp[i-1][j+1] == 1) {
                liveNeigh++;
            }
        }
        
        return liveNeigh;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> temp = board;
        int m = board.size();
	    int n = board[0].size();
        for(int i=0; i < m; i++) {
            for(int j=0; j < n; j++) {
                int res = getLiveNeigh(temp, i, j, m, n);
                if(board[i][j] == 0) {
                    if(res == 3) {
                        board[i][j] = 1;
                    }
                } else {
                    if(res < 2 || res > 3) {
                        board[i][j] = 0;
                    }
                }
            }
        }
    }
};
