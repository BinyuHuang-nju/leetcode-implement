#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1)
            return len;
        int* dp = new int[len];
        dp[0] = 1;
        int i, j, maxlen = 0;
        for (i = 1; i < len; i++) {
            dp[i] = 1;
            for (j = 0; j < i; j++) {
                if (nums[j] < nums[i])
                    dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
            }
            if (maxlen < dp[i])
                maxlen = dp[i];
        }
        return maxlen;
    }
};