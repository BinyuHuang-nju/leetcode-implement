#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len <= 1)
            return 0;
        Day* dp = new Day[len]();
        dp[0].buy = -prices[0];
        for (int i = 1; i < len; i++) {
            dp[i].sell = dp[i - 1].buy + prices[i];
            dp[i].buy = max(dp[i - 1].freeze - prices[i], dp[i-1].buy);
            dp[i].freeze = max(dp[i - 1].freeze, dp[i - 1].sell);
        }
        return max(dp[len - 1].sell, dp[len - 1].freeze);
    }
private:
    struct Day { 
        int buy;
        int sell;
        int freeze;
        Day() :buy(0), sell(0), freeze(0) {}
    };
    int max(int x, int y) {
        return x > y ? x : y;
    }
};