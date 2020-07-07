#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> block(9, vector<bool>(9, false));
        int i, j, num;
        for(i=0;i<9;i++)
            for (j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    num = board[i][j] - '0';
                    row[i][num - 1] = true;
                    col[j][num - 1] = true;
                    block[i / 3 * 3 + j / 3][num - 1] = true;
                }
            }
        dfs(board, row, col, block, 0, 0);
    }
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& row, vector<vector<bool>>& col, \
        vector<vector<bool>>& block, int i, int j) {
        while (board[i][j] != '.') {
            if (i == 8 && j == 8)
                return true;
            if (j == 8) {
                i++;
                j = 0;
            }
            else
                j++;
        }
        for (int num = 0; num < 9; num++) {
            int blockIndex = i / 3 * 3 + j / 3;
            if (!row[i][num] && !col[j][num] && !block[blockIndex][num]) {
                board[i][j] = (char)('0' + 1 + num);
                row[i][num] = true;
                col[j][num] = true;
                block[blockIndex][num] = true;
                if (dfs(board, row, col, block, i, j))
                    return true;
                else {
                    board[i][j] = '.';
                    row[i][num] = false;
                    col[j][num] = false;
                    block[blockIndex][num] = false;
                }
            }
        }
        return false;
    }
};