#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int min = nums[0], max = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (min > nums[i])
                min = nums[i];
            if (max < nums[i])
                max = nums[i];
        }
        int* sum = new int[max - min + 1];
        memset(sum, 0, sizeof(int) * (max - min + 1));
        for (int i = 0; i < nums.size(); i++)
            sum[nums[i] - min] += nums[i];
        if (min == max)
            return sum[0];
        int* dp = new int[max - min + 1];
        dp[0] = sum[0];
        dp[1] = sum[0] > sum[1] ? sum[0] : sum[1];
        for (int i = 2; i < max - min + 1; i++) {
            dp[i] = dp[i - 1] > (dp[i - 2] + sum[i]) ? dp[i - 1] : (dp[i - 2] + sum[i]);
        }
        int result = dp[max - min];
        delete[]sum;
        delete[]dp;
        return result;
    }
};
int main() {
    vector<int> test = { 3,4,2 };
    Solution sol;
    sol.deleteAndEarn(test);
    return 0;
}