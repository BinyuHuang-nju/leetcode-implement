#include <iostream>
using namespace std;
#include <vector>
#include<algorithm>
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int dir[3] = { -1,0,1 };
        int rows = grid.size(), cols = grid.front().size();
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, (vector<int>(cols, INT_MIN))));
        dp[0][0][cols - 1] = grid[0][0] + grid[0][cols - 1];
        for (int i = 1; i < rows; i++) {
            for (int j = 0; j <= i && j < cols; j++) {
                for (int k = cols - 1; k >= cols - 1 - i && k >= j; k--) {
                    int old_j, old_k;
                    for (int u = 0; u < 3; u++) {
                        old_j = j + dir[u];
                        if (old_j < 0 || old_j >= cols || old_j >= i)
                            continue;
                        for (int v = 0; v < 3; v++) {
                            old_k = k + dir[v];
                            if (old_k < 0 || old_k >= cols || old_k < old_j)
                                continue;
                            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][old_j][old_k] + ((j == k) ? grid[i][j] : grid[i][j] + grid[i][k]));
                        }
                    }
                }
            }
        }
        int result = 0;
        for (int j = 0; j < cols && j < rows; j++) {
            for (int k = cols - 1; k >= j && k >= cols - rows; k--)
                result = max(result, dp[rows - 1][j][k]);
        }
        return result;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> grid = { {1,0,0,0,0,0,1},{2,0,0,0,0,3,0},{2,0,9,0,0,0,0},{0,3,0,5,4,0,0},{1,0,2,3,0,0,6} };
    sol.cherryPickup(grid);
    return 0;
}