#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        int M = 1e9 + 7;
        int maxCount = 1;
        for (int roll : rollMax)
            maxCount = max(maxCount, roll);
        vector<vector<vector<long long int>>> dp(n + 1, vector<vector<long long>>(6, vector<long long>(maxCount + 1, 0)));
        for (int i = 0; i < 6; i++)
            dp[1][i][1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < 6; j++) {
                for (int m = 0; m < 6; m++) {
                    if (m == j)
                        continue;
                    for (int n = 1; n <= rollMax[m]; n++)
                        dp[i][j][1] = (dp[i][j][1] + dp[i - 1][m][n]) % M;
                }
                for (int k = 2; k <= rollMax[j]; k++)
                    dp[i][j][k] = dp[i - 1][j][k - 1];
            }
        }
        int result = 0;
        for (int j = 0; j < 6; j++) {
            for (int k = 1; k <= rollMax[j]; k++)
                result = (result + dp[n][j][k]) % M;
        }
        return result;
    }
};
int main() {
    Solution sol;
    vector<int> a = { 1,1,1,2,2,3 };
    sol.dieSimulator(3, a);
    return 0;
}