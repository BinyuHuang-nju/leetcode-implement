#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size(), cur;
        if (len == 0)
            return 0;
        int* dp = new int[len];
        dp[0] = nums[0];
        for (int i = 1; i < len; i++) {
            cur = i > 1 ? dp[i - 2] + nums[i] : nums[i];
            dp[i] = cur > dp[i - 1] ? cur : dp[i - 1];
        }
        int res = dp[len - 1];
        delete[]dp;
        return res;
    }
};