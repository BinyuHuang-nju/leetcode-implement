#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <deque>
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        vector<int> dp(nums.size(), INT_MIN);
        dp[0] = nums[0];
        int result = dp[0];
        deque<int> queNum;
        queNum.push_back(0);
        for (int i = 1; i < nums.size(); i++) {
            if (queNum.front() == i - k - 1)
                queNum.pop_front();
            if (queNum.empty() || dp[queNum.front()] < 0)
                dp[i] = nums[i];
            else
                dp[i] = dp[queNum.front()] + nums[i];
            result = max(result, dp[i]);
            while (!queNum.empty() && dp[queNum.back()] <= dp[i]) {
                queNum.pop_back();
            }
            queNum.push_back(i);
        }
        return result;
    }
};
int main() {
    Solution sol;
    vector<int> nums = { 10,-2,-10,-5,20 };
    sol.constrainedSubsetSum(nums, 2);
    return 0;
}