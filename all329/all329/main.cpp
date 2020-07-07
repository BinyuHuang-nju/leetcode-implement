#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int i, j;
        for (i = 0; i < matrix.size(); i++) {
            for (j = 0; j < matrix[0].size(); j++) {
                if (!dp[i][j])
                    dfs(dp, matrix, i, j);
            }
        }
        int max = 1;
        for (i = 0; i < matrix.size(); i++)
            for (j = 0; j < matrix[0].size(); j++)
                if (max < dp[i][j])
                    max = dp[i][j];
        return max;
    }
    int dfs(vector<vector<int>>& dp, vector<vector<int>>& matrix, int i, int j) {
        if (dp[i][j])
            return dp[i][j];
        dp[i][j] = 1;
        if (i > 0 && matrix[i][j] > matrix[i - 1][j])
            dp[i][j] = bigger(dp[i][j], 1 + dfs(dp, matrix, i - 1, j));
        if (j > 0 && matrix[i][j] > matrix[i][j - 1])
            dp[i][j] = bigger(dp[i][j], 1 + dfs(dp, matrix, i, j - 1));
        if (i<matrix.size() - 1 && matrix[i][j]>matrix[i + 1][j])
            dp[i][j] = bigger(dp[i][j], 1 + dfs(dp, matrix, i + 1, j));
        if (j<matrix[0].size() - 1 && matrix[i][j]>matrix[i][j + 1])
            dp[i][j] = bigger(dp[i][j], 1 + dfs(dp, matrix, i, j + 1));
        return dp[i][j];
    }
    int bigger(int x, int y) {
        return x > y ? x : y;
    }
};