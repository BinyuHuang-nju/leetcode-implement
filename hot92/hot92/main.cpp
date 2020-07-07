#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if (nums.size() == 0)
            return 0;
        unsigned int i, sum = 0;
        for (i = 0; i < nums.size(); i++)
            sum = sum + nums[i];
        if ((sum + S) % 2 == 1)
            return 0;
        if (sum + S == 0)
            return 1 + nums_p(nums, 0, 0);
        return nums_p(nums, 0, (sum + S) / 2);
    }
    int nums_p(vector<int>& nums, int i, int cur) {
        if (i == nums.size() - 1)
            return (nums[i] == cur);
        if (nums[i] > cur)
            return nums_p(nums, i + 1, cur);
        else if(nums[i]==cur)
            return 1+nums_p(nums, i + 1, cur) + nums_p(nums, i + 1, cur - nums[i]);
        return nums_p(nums, i + 1, cur) + nums_p(nums, i + 1, cur - nums[i]);
    }
};
int main() {
    Solution sol;
    vector<int> nums = { 1,1,1,1,1 };
    cout << sol.findTargetSumWays(nums, 3);
    return 0;
}