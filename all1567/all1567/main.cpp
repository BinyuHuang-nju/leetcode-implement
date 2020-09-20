#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos(n, 0);
        vector<int> neg(n, 0);
        int result = 0;
        if (nums[0] > 0) {
            pos[0] = 1;
            result = 1;
        }
        else if (nums[0] < 0)
            neg[0] = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > 0) {
                pos[i] = pos[i - 1] + 1;
                if (neg[i - 1] != 0)
                    neg[i] = neg[i - 1] + 1;
            }
            else if (nums[i] < 0) {
                if (neg[i - 1] != 0)
                    pos[i] = neg[i - 1] + 1;
                neg[i] = pos[i - 1] + 1;
            }
            result = max(result, pos[i]);
        }
        return result;
    }
};
int main() {
    Solution sol;
    vector<int> a = { 0,1,-2,-3,-4 };
    sol.getMaxLen(a);
    return 0;
}