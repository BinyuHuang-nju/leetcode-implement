#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution_false {  //122/125
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1, k = 1;
        sort(nums.begin(), nums.end());
        int cur, res = nums[0] + nums[1] + nums[j];
        while (j - i > 1) {
            cur = target - (nums[i] + nums[j]);
            int min = nums[i + 1];
            for (k = i + 2; k < j; k++) {
                if (abs(cur - min) > abs(cur - nums[k]))
                    min = nums[k];
            }
            res = abs(target - res) < abs(cur - min) ? res : nums[i] + nums[j] + min;
            if (cur - min < 0)
                j--;
            else if (cur - min > 0)
                i++;
            else
                return target;
        }
        return res;
    }
};
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1, k = 1;
        sort(nums.begin(), nums.end());
        int cur, res = nums[0] + nums[1] + nums[j];
        for (i = 0; i < nums.size() - 2; i++) {
            j = i + 1;
            k = nums.size() - 1;
            while (j < k) {
                cur = nums[i] + nums[j] + nums[k];
                if (abs(target - cur) < abs(target - res))
                    res = cur;
                if (target - cur < 0)
                    k--;
                else if (target - cur > 0)
                    j++;
                else
                    return target;
            }
        }
        return res;
    }
};
int main() {
    vector<int> a = { 4,0,5,-5,3,3,0,-4,-5 };
    Solution sol;
    cout << sol.threeSumClosest(a, -2);
    return 0;
}