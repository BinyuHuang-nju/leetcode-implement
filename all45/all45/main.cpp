#include <iostream>
using namespace std;
#include <vector>

class Solution1 {
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        vector<int> dp(nums.size(), INT_MAX);
        dp[0] = 0;
        int i, j, cur;
        for (i = 0; i < nums.size(); i++) {
            cur = i + nums[i] > nums.size() - 1 ? nums.size() - 1 : i + nums[i];
            for (j = i + 1; j <= cur; j++)
                dp[j] = dp[i] + 1 > dp[j] ? dp[j] : dp[i] + 1;
        }
        return dp[nums.size() - 1];
    }
};

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;

        int i, cur = 0, step = 0, next = nums[0];
        for (i = 0; i < nums.size(); i++) {
            next = next > i + nums[i] ? next : i + nums[i];
            if (next >= nums.size() - 1)
                return step + 1;
            if (i == cur) {
                cur = next;
                step++;
            }

        }
        return step;
    }
};