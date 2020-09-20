#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(m + 1, vector<long long>(k + 1, 0)));
        for (int i = 1; i <= m; i++)
            dp[1][m][1] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int l = 1; l <= k && l <= i; l++) {
                    dp[i][j][l] = j * dp[i - 1][j][l];
                    for (int x = 1; x < j; x++)
                        dp[i][j][l] += dp[i - 1][x][l - 1];
                }
            }
        }

    }
};