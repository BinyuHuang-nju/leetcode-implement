#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        bool* dp = new bool[len];
        memset(dp, 0, sizeof(bool) * len);
        dp[0] = true;
        int i, j;
        for (i = 1; i < len; i++) {
            for (j = 0; j < i; j++) {
                if (dp[j] && j + nums[j] >= i) {
                    dp[i] = true;
                    break;
                }
            }
        }
        bool re = dp[len - 1];
        delete[]dp;
        return re;
    }
};