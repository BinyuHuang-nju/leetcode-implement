#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long MOD = 1000000007;
        vector<int> dp(n);
        dp[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = dp[i - 1] * 2;
            if (dp[i] >= MOD) dp[i] -= MOD;
        }

        int l = 0, r = n - 1;
        int res = 0;
        while (l <= r) {
            int sum = nums[l] + nums[r];
            if (sum <= target) {
                res += dp[r - l];
                if (res >= MOD) res -= MOD;
                l++;
            }
            else r--;
        }
        return res;

    }
};