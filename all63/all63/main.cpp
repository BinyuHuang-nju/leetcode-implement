#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
            return 0;
        int len1 = obstacleGrid.size(), len2 = obstacleGrid[0].size();
        vector<vector< unsigned int>> dp(len1, vector<unsigned int>(len2, 0));
        int i, j;
        dp[0][0] = (obstacleGrid[0][0] == 0);
        for (i = 1; i < len1; i++)
            if(!obstacleGrid[i][0])
                dp[i][0] = dp[i - 1][0];
        for (j = 1; j < len2; j++)
            if(!obstacleGrid[0][j])
                dp[0][j] = dp[0][j - 1];
        for (i = 1; i < len1; i++) {
            for (j = 1; j < len2; j++) {
                if (obstacleGrid[i][j] == 1)
                    continue;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return (int)dp[len1 - 1][len2 - 1];
    }
};