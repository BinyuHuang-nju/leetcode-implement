#include <iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int maxSum = nums[0], sum = 0;
        for (int i = 0; i < len; i++) {
            sum = sum + nums[i];
            if (sum > maxSum)
                maxSum = sum;
            if (sum < 0)
                sum = 0;
        }
        return maxSum;
    }
};
int main() {
    vector<int> nums = { -3,-2,0,-1 };
    Solution sol;
    cout << sol.maxSubArray(nums);
    return 0;
}