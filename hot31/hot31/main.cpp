#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = 0, k = nums.size();
        while (i < k) {
            if (nums[i] == 0) {
                swap(nums[i], nums[j]);
                j++;
                i++;
            }
            else if (nums[i] == 1) {
                i++;
            }
            else {
                k--;
                swap(nums[i], nums[k]);
            }
        }
    }
private:
    void swap(int &x, int &y) {
        int temp = x;
        x = y;
        y = temp;
    }
};
int main() {
    vector<int> nums = { 2,0,1 };
    Solution sol;
    sol.sortColors(nums);
    return 0;
}