#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        int low = nums.size(), high = -1;
        int cur_max = nums[0], cur_min = nums[nums.size() - 1], i, j;
        for (i = 1; i < nums.size(); i++) {
            if (cur_max <= nums[i])
                cur_max = nums[i];
            else
                high = i;
        }
        for (i = nums.size() - 2; i >= 0; i--)
        {
            if (cur_min >= nums[i])
                cur_min = nums[i];
            else
                low = i;
        }
        if (low > high)
            return 0;
        return high - low + 1;
    }
};