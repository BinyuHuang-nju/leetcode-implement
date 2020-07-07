#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int point = findTurn(nums, 0, len - 1);
        if (point == -1)
            return findTarget(nums, 0, len - 1, target);
        else {
            int left = findTarget(nums, 0, point - 1, target), right = findTarget(nums, point, len - 1, target);
            return left > right ? left : right;
        }
    }
private:
    int findTurn(vector<int>& nums, int begin, int end) {
        if (end - begin <= 0)
            return -1;
        if (end - begin == 1) {
            if (nums[begin] < nums[end])
                return -1;
            return end;
        }
        int mid = (begin + end) / 2;
        if (nums[mid] > nums[mid - 1])
            return mid;
        int left = findTurn(nums, begin, mid), right = findTurn(nums, mid + 1, end);
        return left > right ? left : right;
    }
    int findTarget(vector<int>& nums, int begin, int end, int target) {
        if (begin > end)
            return -1;
        if (begin == end) {
            if (nums[begin] == target)
                return begin;
            return -1;
        }
        int mid = (begin + end) / 2;
        if (nums[mid] == target)
            return mid;
        int left = findTarget(nums, begin, mid - 1, target), right = findTarget(nums, mid + 1, end, target);
        return left > right ? left : right;
    }
};
int main() {
    vector<int> nums = { 4,5,6,7,0,1,2 };
    Solution sol;
    cout << sol.search(nums, 0);
    return 0;
}