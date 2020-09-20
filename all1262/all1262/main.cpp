#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(3, 0));
        dp[0][nums[0] % 3] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] % 3 == 0){
                dp[i][0] = dp[i - 1][0] + nums[i];
                if (dp[i - 1][1] != 0)
                    dp[i][1] = dp[i - 1][1] + nums[i];
                if (dp[i - 1][2] != 0)
                    dp[i][2] = dp[i - 1][2] + nums[i];
            }
            else if (nums[i] % 3 == 1) {
                if (dp[i - 1][2] != 0)
                    dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] + nums[i]);
                else
                    dp[i][0] = dp[i - 1][0];
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + nums[i]);
                if (dp[i - 1][1] != 0)
                    dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + nums[i]);
                else
                    dp[i][2] = dp[i - 1][2];
            }
            else {
                if (dp[i - 1][1] != 0)
                    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + nums[i]);
                else
                    dp[i][0] = dp[i - 1][0];
                if (dp[i - 1][2] != 0)
                    dp[i][1] = max(dp[i - 1][1], dp[i - 1][2] + nums[i]);
                else
                    dp[i][1] = dp[i - 1][1];
                dp[i][2] = max(dp[i - 1][2], dp[i - 1][0] + nums[i]);
            }
        }
        return dp[nums.size() - 1][0];
    }
};
int main() {
    Solution sol;
    vector<int> a = { 3,6,5,1,8 };
    int x =sol.maxSumDivThree(a);
    return 0;
}