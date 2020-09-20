#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        int n = houses.size();
        sort(houses.begin(), houses.end());
        if (n <= k)
            return 0;
        vector<vector<int>> dp(n, vector<int>(k + 1, INT_MAX));
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int mid = (i + j) / 2;
                for (int m = i; m <= j; m++)
                    cost[i][j] += abs(houses[m] - houses[mid]);
            }
        }
        for (int m = 1; m <= k; m++)
            dp[m - 1][m] = 0;
        for (int i = 0; i < n; i++)
            dp[i][1] = cost[0][i];
        for (int i = 1; i < n; i++) {
            for (int j = 2; j <= i && j <= k; j++) {
                for (int kk = j - 1; kk <= i; kk++) {
                    dp[i][j] = min(dp[i][j], dp[kk - 1][j - 1] + cost[kk][i]);
                }
            }
        }
        return dp[n - 1][k];
    }
};
int main() {
    Solution sol;
    vector<int> a = { 1,8,12,10,3 };
    sol.minDistance(a, 3);
    return 0;
}