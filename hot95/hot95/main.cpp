#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> lastSum(nums.size() + 1, 0);
        int i, j;
        int res = 0;
        for (i = 1; i <= nums.size(); i++)
            lastSum[i] = lastSum[i - 1] + nums[i - 1];
        for (i = 0; i < nums.size(); i++)
            for (j = i + 1; j <= nums.size(); j++)
                if (lastSum[j] - lastSum[i] == k)
                    res++;
        return res;
    }
};
int main() {
    vector<int> nums = { 1,1,1 };
    Solution sol;
    cout << sol.subarraySum(nums, 2);
    return 0;
}