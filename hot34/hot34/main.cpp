#include <iostream>
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || word.length() == 0)
            return false;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        int i, j;
        for (i = 0; i < board.size(); i++) {
            for (j = 0; j < board[0].size(); j++) {
                if (dfs(board, word, visited, i, j, 0))
                    return true;
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>>& board, string word,vector<vector<bool>>& visited, int i, int j, int depth) {
        if (depth == word.length())
            return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[depth])
            return false;
        bool res = false;
        if (visited[i][j] == false) {
            visited[i][j] = true;
            if (dfs(board, word, visited, i - 1, j, depth + 1) || dfs(board, word, visited, i, j - 1, depth + 1) ||
                dfs(board, word, visited, i + 1, j, depth + 1) || dfs(board, word, visited, i, j +1 , depth + 1))
                res = true;
            visited[i][j] = false;
        }
        return res;
    }
};