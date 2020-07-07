#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() <= 2 || board[0].size() <= 2)
            return;
        vector<vector<bool>> isO_notSurrounded(board.size(), vector<bool>(board[0].size(), false));
        int i, j;
        for (i = 0; i < board.size(); i++) {
            if (i == 0 || i == board.size() - 1) {
                for (j = 0; j < board[0].size(); j++)
                    if (board[i][j] == 'O' && !isO_notSurrounded[i][j])
                        dfs(board, isO_notSurrounded, i, j);
            }
            else {
                if (board[i][0] == 'O'&&!isO_notSurrounded[i][0])
                    dfs(board, isO_notSurrounded, i, 0);
                if (board[i][board[0].size() - 1] == 'O' && !isO_notSurrounded[i][board[0].size() - 1])
                    dfs(board, isO_notSurrounded, i, board[0].size() - 1);
            }
        }
        for (i = 0; i < board.size(); i++)
            for (j = 0; j < board[0].size(); j++)
                if (board[i][j] == 'O' && !isO_notSurrounded[i][j])
                    board[i][j] = 'X';
    }
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& judge, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return;
        if (board[i][j] == 'X'||judge[i][j])
            return;
        judge[i][j] = true;
        dfs(board, judge, i - 1, j);
        dfs(board, judge, i + 1, j);
        dfs(board, judge, i, j - 1);
        dfs(board, judge, i, j + 1);
    }
};
int main() {
    vector<vector<char>> board = { {'X','X','X','X'},{'X','O','O','X'}, {'X','X','O','X'}, {'X','O','X','X'} };
    Solution sol;
    sol.solve(board);
    return 0;
}