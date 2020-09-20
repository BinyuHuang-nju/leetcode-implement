#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<vector<int>>> count(3, vector<vector<int>>(9, vector<int>(9, 0)));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int digit = board[i][j] - '1';
                    count[0][i][digit]++;
                    if (count[0][i][digit] > 1)
                        return false;
                    count[1][j][digit]++;
                    if (count[1][j][digit] > 1)
                        return false;
                    int num = i / 3 * 3 + j / 3;
                    count[2][num][digit]++;
                    if (count[2][num][digit] > 1)
                        return false;
                }
            }
        }
        return true;
    }
};