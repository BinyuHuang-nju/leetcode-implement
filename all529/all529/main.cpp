#include <iostream>
using namespace std;
#include <vector>

class Solution {
private:
    int direction[8][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        //vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        dfs(board, click[0], click[1]);
        return board;
    }
    void dfs(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
            return;
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return;
        }
        if (board[x][y] == 'E') {
            int count = 0;
            for (int i = 0; i < 8; i++) {
                if (x + direction[i][0] < 0 || y + direction[i][1] < 0 || x + direction[i][0] >= board.size() || y + direction[i][1] >= board[0].size())
                    continue;
                if (board[x + direction[i][0]][y + direction[i][1]] == 'M')
                    count++;
            }
            if (count == 0) {
                board[x][y] = 'B';
                for (int i = 0; i < 8; i++) {
                    if (x + direction[i][0] < 0 || y + direction[i][1] < 0 || x + direction[i][0] >= board.size() || y + direction[i][1] >= board[0].size())
                        continue;
                    if (board[x + direction[i][0]][y + direction[i][1]] == 'E')
                        dfs(board, x + direction[i][0], y + direction[i][1]);
                }
            }
            else {
                board[x][y] = (char)('0' + count);
            }
        }
    }
};