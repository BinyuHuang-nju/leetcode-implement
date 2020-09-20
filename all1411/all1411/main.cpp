#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution1 {
public:
    int numOfWays(int n) {
        const int statesnum = 12;
        const long long M = 1e9 + 7;
        vector<int> states = { 0 * 9 + 1 * 3 + 0,0 * 9 + 1 * 3 + 2,0 * 9 + 2 * 3 + 0,0 * 9 + 2 * 3 + 1,
        1 * 9 + 0 * 3 + 1,1 * 9 + 0 * 3 + 2,1 * 9 + 2 * 3 + 0,1 * 9 + 2 * 3 + 1,
        2 * 9 + 0 * 3 + 1,2 * 9 + 0 * 3 + 2,2 * 9 + 1 * 3 + 0,2 * 9 + 1 * 3 + 2 };
        vector<vector<bool>> can_connect(statesnum, vector<bool>(statesnum, false));
        for (int i = 0; i < statesnum; i++) {
            int xi = states[i] / 9, yi = states[i] % 9 / 3, zi = states[i] % 3;
            for (int j = i + 1; j < statesnum; j++) {
                int xj = states[j] / 9, yj = states[j] % 9 / 3, zj = states[j] % 3;
                if (xi != xj && yi != yj && zi != zj) {
                    can_connect[i][j] = can_connect[j][i] = true;
                }
            }
        }
        vector<vector<long long>> dp(n, vector<long long>(statesnum, 0));
        for (int j = 0; j < statesnum; j++)
            dp[0][j] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < statesnum; j++) {
                for (int k = 0; k < statesnum; k++) {
                    if (can_connect[j][k]) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % M;
                    }
                }
            }
        }
        long long result = 0;
        for (int j = 0; j < statesnum; j++)
            result = (result + dp[n - 1][j]) % M;
        return (int)result;
    }
};
class Solution {
public:
    int numOfWays(int n) {
        const long long M = 1e9 + 7;
        vector<vector<long long>> dp(n, vector<long long>(2, 0));
        dp[0][0] = dp[0][1] = 6;
        for (int i = 1; i < n; i++) {
            dp[i][0] = (3 * dp[i - 1][0] + 2 * dp[i - 1][1]) % M;
            dp[i][1] = (2 * dp[i - 1][0] + 2 * dp[i - 1][1]) % M;
        }
        return (int)((dp[n - 1][0] + dp[n - 1][1]) % M);
    }
};
int main() {
    Solution sol;
    int x=sol.numOfWays(3);
    return 0;
}