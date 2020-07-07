#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution { //eceeds time limitation
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (target <= 0)
            return 0;
        int res = 0;
        dfs(nums, target,res);
        return res;
    }
    void dfs(vector<int>& nums, int target, int& res) {
        if (target == 0)
            res++;
        else {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= target) {
                    dfs(nums, target - nums[i], res);
                }
            }
        }
    }
};

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        int i, j;
        for (i = 1; i <= target; i++) {
            for (j = 0; j < nums.size(); j++) {
                if (i >= nums[j])
                    dp[i] = dp[i] + dp[i - nums[j]];
                else
                    break;
            }
        }
        return (int)dp[target];
    }
};