#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size(), i;
        for (i = len - 2; i >= 0; i--)
            if (nums[i] < nums[i + 1])
                break;
        int temp, j, k;
        for (j = i + 1, k = len - 1; j < k; j++, k--) {
            temp = nums[j];
            nums[j] = nums[k];
            nums[k] = temp;
        }
        if (i == -1)
            return;
        for(j=i+1;j<len;j++)
            if (nums[j] > nums[i]) {
                temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
                break;
            }
    }
};

int main() {
    vector<int> nums = { 1,2,3,5,4,9,8,7,6 };
    Solution sol;
    sol.nextPermutation(nums);
    return 0;
}