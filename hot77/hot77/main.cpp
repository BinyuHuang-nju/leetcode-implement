#include <iostream>
using namespace std;
#include <vector>
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int n = nums.size();
        nums.push_back(1);
        nums.push_back(1);
        for (int i = nums.size() - 2; i >= 0; i--)
            nums[i + 1] = nums[i];
        nums[0] = 1;
        int** dp = new int* [n + 2];
        for (int i = 0; i < n + 2; i++)
            dp[i] = new int[n + 2];
        int i, j, k, res;
        for (i = 0; i < n + 2; i++)
            dp[i][i] = nums[i];
        for (i = n + 1; i >= 0; i--) {
            for (j = i + 1; j < n + 2; j++) {
                res = 0;
                for (k = i; k <= j; k++)
                    res = max(res, dp[i][k] + dp[k][j] + nums[i] * nums[k] * nums[j]);
                dp[i][j] = res;
            }
        }
        return dp[0][n + 1];
    }
    int max(int x, int y) {
        return x > y ? x : y;
    }
};