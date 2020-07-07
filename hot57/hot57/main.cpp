#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        if (len == 1)
            return nums[0];
        int major = nums[0], cur = 1, i;
        for (i = 1; i < len; i++) {
            if (major == nums[i])
                cur++;
            else {
                if (cur == 1)
                    major = nums[i];
                else
                    cur--;
            }
        }
        cur = 0;
        for (i = 0; i < len; i++)
            if (major == nums[i])
                cur++;
        if (cur > len / 2)
            return major;
        return -1;
    }
};