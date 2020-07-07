#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return 0;
        if (len == 1)
            return nums[0];
        if (len == 2)
            return max(nums[0], nums[1]);
        vector<int> dp1(len, 0);
        vector<int> dp2(len, 0);
        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);
        for (int i = 2; i <= len - 2; i++)
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
        dp2[1] = nums[1];
        dp2[2] = max(nums[1],nums[2]);
        for (int i = 3; i <= len - 1; i++)
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i]);
        return max(dp1[len - 2], dp2[len - 1]);
    }
private:
    int max(int x, int y) {
        return x > y ? x : y;
    }
};
int main() {
    vector<int> a = { 0,0 };
    Solution sol;
    cout << sol.rob(a);
    return 0;
}