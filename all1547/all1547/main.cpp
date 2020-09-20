#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        cuts.push_back(0);
        sort(cuts.begin(), cuts.end());
        cuts.push_back(n);
        vector<vector<int>> dp(m + 2, vector<int>(m + 2, 0));
        for (int i = m; i >= 1; i--) {
            dp[i][i] = cuts[i + 1] - cuts[i - 1];
            for (int j = i + 1; j <= m; j++) {
                int tmp = INT_MAX;
                for (int k = i; k <= j; k++)
                    tmp = min(tmp, dp[i][k - 1] + dp[k + 1][j]);
                dp[i][j] = tmp + cuts[j + 1] - cuts[i - 1];
            }
        }
        return dp[1][m];
    }
};
int main() {
    Solution sol;
    vector<int> a = { 3,5,1,4 };
    sol.minCost(7, a);
    return 0;
}