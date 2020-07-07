#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
/*class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() < 2)
            return false;
        sort(nums.begin(), nums.end());
        int mid = nums.size() / 2, leftres = 0, rightres = 0;
        int i;
        for (i = 0; i < mid; i++)
            leftres = leftres + nums[i];
        for (i = mid; i < nums.size(); i++)
            rightres = rightres + nums[i];
        while (mid < nums.size()) {
            if (leftres > rightres)
                return false;
            else if (leftres == rightres)
                return true;

            leftres = leftres + nums[mid];
            rightres = rightres - nums[mid];
            mid++;
        }
        return false;
    }
};*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() < 2)
            return false;
        int sum = 0, i, s;
        for (i = 0; i < nums.size(); i++)
            sum = sum + nums[i];
        if (sum % 2 == 1)
            return false;
        sum = sum / 2;
        vector<vector<bool>> dp(nums.size(), vector<bool>(sum + 1, false));
        for (i = 0; i < nums.size(); i++) {
            for (s = 0; s <= sum; s++) {
                if (i == 0)
                    dp[0][s] = (nums[0] == s);
                else {
                    dp[i][s] = dp[i - 1][s] || ((s >= nums[i]) ? dp[i - 1][s - nums[i]] : false);
                }
            }
        }
        return dp[nums.size() - 1][sum];
    }
};
int main() {
    vector<int> nums = { 1,5,11,5 };
    Solution sol;
    cout << sol.canPartition(nums);
    return 0;
}