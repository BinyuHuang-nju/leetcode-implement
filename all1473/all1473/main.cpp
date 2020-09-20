#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        if (m < target)
            return -1;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n + 1, vector<int>(target + 1, INT_MAX)));
        if (houses[0] == 0) {
            for (int j = 1; j <= n; j++)
                dp[0][j][1] = cost[0][j - 1];
        }
        else
            dp[0][houses[0]][1] = 0;
        for (int i = 1; i < m; i++) {
            if (houses[i - 1] == 0 && houses[i] == 0) {
                for (int j = 1; j <= n; j++) {
                    for (int k = 1; k <= target && k <= i; k++) {
                        if (dp[i - 1][j][k] != INT_MAX)
                            dp[i][j][k] = dp[i - 1][j][k] + cost[i][j - 1];
                    }
                    for (int k = 2; k <= target && k <= i + 1; k++) {
                        for (int pre_j = 1; pre_j <= n; pre_j++) {
                            if (pre_j == j)
                                continue;
                            if (dp[i - 1][pre_j][k - 1] != INT_MAX)
                                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][pre_j][k - 1] + cost[i][j - 1]);
                        }
                    }
                }
            }
            else if (houses[i - 1] != 0 && houses[i] == 0) {
                int pre_j = houses[i - 1];
                for (int k = 1; k <= target && k <= i; k++) {
                    if (dp[i - 1][pre_j][k] != INT_MAX)
                        dp[i][pre_j][k] = dp[i - 1][pre_j][k] + cost[i][pre_j - 1];
                }
                for (int j = 1; j <= n; j++) {
                    if (pre_j == j)
                        continue;
                    for (int k = 2; k <= target && k <= i + 1; k++) {
                        if (dp[i - 1][pre_j][k - 1] != INT_MAX)
                            dp[i][j][k] = dp[i - 1][pre_j][k - 1] + cost[i][j - 1];
                    }
                }
            }
            else if (houses[i - 1] != 0 && houses[i] != 0) {
                int pre_j = houses[i - 1], j = houses[i];
                if (pre_j == j) {
                    for (int k = 1; k <= target && k <= i; k++) {
                        if (dp[i - 1][j][k] != INT_MAX)
                            dp[i][j][k] = dp[i - 1][j][k];
                    }
                }
                else {
                    for (int k = 2; k <= target && k <= i + 1; k++) {
                        if (dp[i - 1][pre_j][k - 1] != INT_MAX)
                            dp[i][j][k] = dp[i - 1][pre_j][k - 1];
                    }
                }
            }
            else { // houses[i-1]==0&&houses[i]!=0
                int j = houses[i];
                for (int k = 1; k <= target && k <= i; k++) {
                    if (dp[i - 1][j][k] != INT_MAX)
                        dp[i][j][k] = dp[i - 1][j][k];
                }
                for (int pre_j = 1; pre_j <= n; pre_j++) {
                    if (pre_j == j)
                        continue;
                    for (int k = 2; k <= target && k <= i + 1; k++) {
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][pre_j][k - 1]);
                    }
                }
            }
        }
        int result = INT_MAX;
        for (int j = 1; j <= n; j++) {
            result = min(result, dp[m - 1][j][target]);
        }
        return (result == INT_MAX) ? -1 : result;
    }
};
int main() {
/*    vector<int> houses = { 0,0,0,0,0 };
    vector<vector<int>> cost = { {1,10},{10,1},{10,1},{1,10},{5,1} };
    Solution sol;
    sol.minCost(houses, cost, 5, 2, 3);*/
/*    vector<int> houses = { 0,2,1,2,0 };
    vector<vector<int>> cost = { {1,10},{10,1},{10,1},{1,10},{5,1} };
    Solution sol;
    sol.minCost(houses, cost, 5, 2, 3);
  */
/*    vector<int> houses = { 0,0,0,0,0 };
    vector<vector<int>> cost = { {1,10},{10,1},{1,10},{10,1},{1,10} };
    Solution sol;
    sol.minCost(houses, cost, 5, 2, 5);*/
    vector<int> houses = { 3,1,2,3 };
    vector<vector<int>> cost = { {1,1,1},{1,1,1},{1,1,1},{1,1,1},{1,1,1} };
    Solution sol;
    sol.minCost(houses, cost, 4, 3, 3);
    return 0;
}