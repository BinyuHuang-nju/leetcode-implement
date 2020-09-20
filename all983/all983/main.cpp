#include <iostream>
using namespace std;
#include <vector>
#include <cmath>
#include <algorithm>
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        if (days.size() == 0)
            return 0;
        int maxDay = days[days.size() - 1];
        vector<int> dp(maxDay + 1, 0);
        int curIndex = 0;
        for (int i = 1; i <= maxDay; i++) {
            if (i < days[curIndex])
                dp[i] = dp[i - 1];
            else {
                dp[i] = dp[i - 1] + costs[0];
                dp[i] = min(dp[i], i >= 7 ? dp[i - 7] + costs[1] : costs[1]);
                dp[i] = min(dp[i], i >= 30 ? dp[i - 30] + costs[2] : costs[2]);
                curIndex++;
            }
        }
        return dp[maxDay];
    }
};