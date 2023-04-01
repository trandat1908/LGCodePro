// https://leetcode.com/problems/sudoku-solver/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int N = 9;
    bool checkValid(vector<vector<char>>& board,const int& x,const int& y,const char& c) {
        for(int i=0; i<9; ++i) {
            if(board[x][i]==c||board[i][y]==c) return false;
        }
        int a = x/3, b = y/3;

        for(int i=(a*3); i<(a*3+3); ++i) {
            for(int j=(b*3); j<(b*3+3); ++j) {
                if(board[i][j]==c) return false;
            }
        }
        return true;
    }
    void printBoard(vector<vector<char>> board) {
        for(int i=0; i< (int)board.size(); ++i) {
            for(int j=0; j<(int)board[i].size(); ++j) {
                cout<<board[i][j]<<' ';
            }
            cout<<endl;
        }
    }
    bool solveSudoku(vector<vector<char>>& board, int row, int col) {
        if(row==N-1 && col == N) {
            return true;
        }
        if(col==N) {
            row++;
            col = 0;
        }
        if(board[row][col]!='.') {
           return solveSudoku(board, row, col + 1);
        }
        for(int k=1; k<=N; ++k) {
            char c = (char) k+48;
            if(checkValid(board, row, col, c)){
                board[row][col] = c;
                if(solveSudoku(board, row, col + 1))
                    return true;
            }
            board[row][col] ='.';
        }
        return false;
    }

};

int main()
{
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                                  {'6','.','.','1','9','5','.','.','.'},
                                  {'.','9','8','.','.','.','.','6','.'},
                                  {'8','.','.','.','6','.','.','.','3'},
                                  {'4','.','.','8','.','3','.','.','1'},
                                  {'7','.','.','.','2','.','.','.','6'},
                                  {'.','6','.','.','.','.','2','8','.'},
                                  {'.','.','.','4','1','9','.','.','5'},
                                  {'.','.','.','.','8','.','.','7','9'}};
    Solution *s = new Solution();
    if(s->solveSudoku(board, 0, 0))
        s->printBoard(board);
    return 0;
}
