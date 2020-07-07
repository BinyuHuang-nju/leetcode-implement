#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int i, j;
        int** dp = new int*[m];
        for (i = 0; i < m; i++)
            dp[i] = new int[n];
        dp[0][0] = 1;
        for (i = 1; i < m; i++)
            dp[i][0] = 1;
        for (j = 1; j < n; j++)
            dp[0][j] = 1;
        for(i=1;i<m;i++)
            for (j = 1; j < n; j++) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        int res = dp[m - 1][n - 1];
        delete[]dp;
        return res;
    }
};