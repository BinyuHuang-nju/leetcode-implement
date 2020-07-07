#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        if (k >= prices.size() / 2)
            return greedy(prices);
        int i, j;
        vector<vector<vector<int>>> dp\
            (prices.size(), vector<vector<int>>(k+1, vector<int>(2, 0)));
        for (i = 0; i <= k; i++) {
            dp[0][i][0] = 0;
            dp[0][i][1] = -prices[0];
        }
        for (i = 1; i < prices.size(); i++) {
            for (j = 0; j <= k; j++) {
                if(j==0)
                    dp[i][j][0] = dp[i - 1][j][0];
                else {
                    dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j - 1][1] + prices[i]);
                }
                dp[i][j][1] = max(dp[i - 1][j][1],dp[i-1][j][0]-prices[i]);
            }
        }
        int res = dp[prices.size() - 1][0][0];
        for (i = 1; i <= k; i++)
            res = max(res, dp[prices.size() - 1][i][0]);
        return res;
    }
    int greedy(vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); i++)
            if (prices[i] > prices[i - 1])
                res = res + (prices[i] - prices[i - 1]);
        return res;
    }
    int max(int x, int y) {
        return x > y ? x : y;
    }
};