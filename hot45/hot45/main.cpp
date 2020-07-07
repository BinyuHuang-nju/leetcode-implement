#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len < 2)
            return 0;
        //int* dp = new int[len];
       // dp[0] = 0;
        int i, j, max = 0, min = prices[0], cur;
        for (i = 1; i < len; i++) {
            cur = prices[i] - min;
            max = max > cur ? max : cur;
            min = prices[i] < min ? prices[i] : min;

        }
        //delete[]dp;
        return max;
    }
};
int main() {
    vector<int> prices = { 7,1,5,3,6,4 };
    Solution sol;
    cout << sol.maxProfit(prices);
    return 0;
}