#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (target <= nums[i])
                return i;
        }
        return n;
    }
};
int main() {
    Solution sol;
    vector<int>a = { 1,3,5,6 };
    int x = sol.searchInsert(a, 5);
    return 0;
}