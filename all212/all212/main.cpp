#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <cstring>
#include <map>

class Solution {  // succeeds, but exceeds time limitation
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if (board.size() == 0 || board[0].size() == 0)
            return res;
        for (string word : words) {
            map<int, int> visited;
            int i, j;
            bool succeed = false;
            for (i = 0; i < board.size(); i++) {
                for (j = 0; j < board[0].size(); j++) {
                    if (board[i][j] == word[0]) {
                        visited[i * board[0].size() + j] = 1;
                        if (findWord(board, word, 1, i, j, visited)) {
                            succeed = true;
                            break;
                        }
                        visited[i * board[0].size() + j] = 0;
                    }
                }
                if (succeed)
                    break;
            }
            if (succeed)
                res.push_back(word);
        }
        return res;
    }
    bool findWord(vector<vector<char>>& board, string word, int match,\
        int i, int j,map<int,int>& visited ) {
        if (match == word.length())
            return true;
        int x, y;
        if (i > 0 && board[i - 1][j] == word[match]&&!(visited[(i-1)*board[0].size()+j]==1)) {
            visited[(i - 1) * board[0].size() + j] = 1;
            if (findWord(board, word, match + 1, i - 1, j, visited))
                return true;
            visited[(i - 1) * board[0].size() + j] = 0;
        }
        if (i < board.size()-1 && board[i + 1][j] == word[match] && !(visited[(i + 1) * board[0].size() + j] == 1)) {
            visited[(i + 1) * board[0].size() + j] = 1;
            if (findWord(board, word, match + 1, i + 1, j, visited))
                return true;
            visited[(i + 1) * board[0].size() + j] = 0;
        }
        if (j > 0 && board[i][j-1] == word[match] && !(visited[i * board[0].size() + j-1] == 1)) {
            visited[i * board[0].size() + j-1] = 1;
            if (findWord(board, word, match + 1, i , j-1, visited))
                return true;
            visited[i * board[0].size() + j-1] = 0;
        }
        if (j < board[0].size()-1 && board[i][j + 1] == word[match] && !(visited[i * board[0].size() + j + 1] == 1)) {
            visited[i * board[0].size() + j + 1] = 1;
            if (findWord(board, word, match + 1, i, j + 1, visited))
                return true;
            visited[i * board[0].size() + j + 1] = 0;
        }
        return false;
    }
};