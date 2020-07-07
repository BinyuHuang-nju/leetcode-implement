#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size(), base, left, right;
        vector<vector<int>> re;
        sort(nums.begin(), nums.end());
        if (len < 3)
            return re;
        if (nums[0] == 0) {
            if (nums[1] == 0 && nums[2] == 0) {
                re.push_back({ 0,0,0 });
            }
            return re;
        }
        base = 0;
        while (base < len - 2) {
            if (nums[base] > 0)
                return re;
            left = base + 1;
            right = len - 1;
            while (left < right) {
                if (nums[base] + nums[left] + nums[right] == 0) {
                    re.push_back({ nums[base],nums[left],nums[right] });
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                }
                else if (nums[base] + nums[left] + nums[right] < 0)
                    left++;
                else
                    right--;
            }
            while (base < len - 2 && nums[base] == nums[base + 1])
                base++;
            base++;
        }
        return re;
    }
};
int main() {
    int num, temp;
    cin >> num;
    vector<int> nums;
    for (int i = 0; i < num; i++) {
        cin >> temp;
        nums.emplace_back(temp);
    }
    Solution sol;
    vector<vector<int>> re = sol.threeSum(nums);
    return 0;
}