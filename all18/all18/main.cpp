#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> results;
        int len = nums.size();
        if (len < 4)
            return results;
        sort(nums.begin(), nums.end());
        int i, j, k, l;
        for (i = 0; i < len - 3; i++) {
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            for (j = i + 1; j < len - 2; j++) {
                if (j > i + 1 && nums[j - 1] == nums[j])
                    continue;
                k = j + 1;
                l = len - 1;
                int new_target = target - nums[i] - nums[j];
                while (k < l) {
                    if (nums[k] + nums[l] == new_target) {
                        //cout << i << " " << j << " " << k << " " << l << endl;
                        results.push_back({ nums[i],nums[j],nums[k],nums[l] });
                        while (k < l && nums[k] == nums[k + 1])
                            k++;
                        while (k < l && nums[l - 1] == nums[l])
                            l--;
                        k++;
                        l--;
                    }
                    else if (nums[k] + nums[l] < new_target)
                        k++;
                    else
                        l--;
                }
            }
        }
        return results;
    }
};
int main() {
    vector<int> a = { 0,0,4,-2,-3,-2,-2,-3};
    Solution sol;
    sol.fourSum(a, -1);
    return 0;
}