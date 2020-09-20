#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution1 {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size(), sum = 0;
        vector<int> suffix(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            sum += stoneValue[i];
            suffix[i + 1] = sum;
        }
        vector<int> dp(n+1, 0);
        dp[n - 1] = suffix[n];
        for (int i = n-2; i >= 0; i--) {
            int rival_min = INT_MAX;
            for (int j = i + 1; j <= n && j <= i + 3; j++)
                rival_min = min(rival_min, dp[j]);
            dp[i] = suffix[i + 1] - rival_min;
        }
        if (dp[0] * 2 == sum)
            return "Tie";
        return dp[0] * 2 > sum ? "Alice" : "Bob";
    }
};
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> preffix(n + 1, 0);
        for (int i = 1; i <= n; i++)
            preffix[i] = preffix[i - 1] + stoneValue[i - 1];
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = INT_MIN;
            for (int j = i + 1; j <= n && j <= i + 3; j++)
                dp[i] = max(dp[i], preffix[j]-preffix[i]-dp[j]);
        }
        if (dp[0] == 0)
            return "Tie";
        return dp[0] > 0 ? "Alice" : "Bob";
    }
};
int main() {
    Solution sol;
    vector<int> a = { 1,2,3,-1,-2,-3,7 };
    sol.stoneGameIII(a);
    return 0;
}