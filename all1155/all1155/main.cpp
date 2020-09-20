#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int>> dp(d + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= d; i++) {
            for (int j = 1; j <= target; j++) {
                for (int x = 1; x <= f && x <= j; x++)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % 1000000007;
            }
        }
        return dp[d][target];
    }
};
int main() {
    Solution sol;
    int a = sol.numRollsToTarget(30, 30, 500);
    return 0;
}