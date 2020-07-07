#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return 0;
        int left = 0, right = 0, diff = len + 1, sum = nums[0];
        //bool stop = false;
        while (1) {
            if (sum >= s) {
                if (left == right)
                    return 1;
                diff = diff > right - left + 1 ? right - left + 1 : diff;
                sum = sum - nums[left];
                left++;
            }
            else {
                if (right == len - 1) {
                    if (diff == len + 1)
                        return 0;
                    else
                        return diff;
                }
                else {
                    right++;
                    sum = sum + nums[right];
                }
            }
        }
        return diff;
    }
};