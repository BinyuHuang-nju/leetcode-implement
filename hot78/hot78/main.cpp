#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        if (coins.size() < 1)
            return -1;
        if (amount == 0)
            return 0;
        int len = coins.size(), i, j;
        int** dp = new int* [len];
        for (i = 0; i < len; i++)
            dp[i] = new int[amount + 1];
        for (i = 0; i < len; i++)
            dp[i][0] = 0;
        for (j = 0; j <= amount; j++) {
            if (j % coins[0] == 0)
                dp[0][j] = j / coins[0];
            else
                dp[0][j] = INT_MAX;
        }
        for(i=1;i<len;i++)
            for (j = 1; j <= amount; j++) {
                if (j < coins[i]) {
                    /*if (dp[i - 1][j] == INT_MAX)
                        dp[i][j] = INT_MAX;
                    else
                        dp[i][j] = dp[i - 1][j];*/
                    dp[i][j] = dp[i - 1][j];
                }
                else {
                    if (dp[i - 1][j] == INT_MAX && dp[i][j - coins[i]] == INT_MAX)
                        dp[i][j] = INT_MAX;
                    else if (dp[i - 1][j] == INT_MAX)
                        dp[i][j] = dp[i][j - coins[i]] + 1;
                    else if (dp[i][j - coins[i]] == INT_MAX)
                        dp[i][j] = dp[i - 1][j];
                    else
                        dp[i][j] = (dp[i - 1][j] > dp[i][j - coins[i]] + 1) ? dp[i][j - coins[i]] + 1 : dp[i - 1][j];
                }
            }
        if (dp[len - 1][amount] == INT_MAX)
            return -1;
        return dp[len - 1][amount];
    }
};
int main() {
    vector<int> coins = { 1,2,5 };
    Solution sol;
    cout << sol.coinChange(coins, 11);
    return 0;
}