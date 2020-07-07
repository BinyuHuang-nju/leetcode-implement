#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<bool>> cover(n, vector<bool>(n, false));
        vector<vector<int>> queen;
        int res = 0;
        dfs(queen, cover, res, 0, n);
        return res;
    }
    void dfs(vector<vector<int>>& queen, vector<vector<bool>>& cover, \
        int& res, int cur, int n\
    ) {
        if (cur == n) {
            res++;
        }
        else if (cur == 0) {
            for (int i = 0; i < n; i++) {
                queen.push_back({ 0,i });
                queenCover(0, i, n, cover);
                dfs(queen, cover, res, 1, n);
                queen.pop_back();
                queenClear(n, cover);
            }
        }
        else {
            for (int j = 0; j < n; j++) {
                if (!cover[cur][j]) {
                    queen.push_back({ cur,j });
                    queenCover(cur, j, n, cover);
                    dfs(queen, cover, res, cur + 1, n);
                    queen.pop_back();
                    queenClear(n, cover);
                    for (int k = 0; k < cur; k++)
                        queenCover(queen[k][0], queen[k][1], n, cover);
                }
            }
        }
    }
    void queenCover(int x, int y, int n, vector<vector<bool>>& cover\
    ) {
        int i, j;
        for (i = 0; i < n; i++)
            cover[i][y] = true;
        for (j = 0; j < n; j++)
            cover[x][j] = true;
        for (i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--)
            cover[i][j] = true;
        for (i = x + 1, j = y - 1; i < n && j >= 0; i++, j--)
            cover[i][j] = true;
        for (i = x - 1, j = y + 1; i >= 0 && j < n; i--, j++)
            cover[i][j] = true;
        for (i = x + 1, j = y + 1; i < n && j < n; i++, j++)
            cover[i][j] = true;
    }
    void queenClear(int n, vector<vector<bool>>& cover) {
        for (int i = 0; i < n; i++) {
            cover[i].assign(n, false);
        }
    }
};

int main() {
    vector<vector<int>> queen = { {1,2},{7,4},{7,3},{5,5} };
    sort(queen.begin(), queen.end(), [](const vector<int> q1, const vector<int> q2)\
    {return q1[0] < q2[0]; }); //lambda
    for (int i = 0; i < 4; i++)
        queen[i].assign(2, 8);
    return 0;
}