#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int i, j;
        int len1 = grid.size(), len2 = grid[0].size();
        int** dp = new int* [len1];
        for (i = 0; i < len1; i++)
            dp[i] = new int[len2];
        for(i=0;i<len1;i++)
            for (j = 0; j < len2; j++) {
                if (i == 0 && j == 0)
                    dp[0][0] = grid[0][0];
                else if (i == 0)
                    dp[0][j] = dp[0][j - 1] + grid[0][j];
                else if (j == 0)
                    dp[i][0] = dp[i - 1][0] + grid[i][0];
                else {
                    dp[i][j] = grid[i][j] + (dp[i - 1][j] > dp[i][j - 1] ? dp[i][j - 1] : dp[i - 1][j]);
                }
            }
        int res = dp[len1 - 1][len2 - 1];
        delete[]dp;
        return res;
    }
};