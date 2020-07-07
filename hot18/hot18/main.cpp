#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> re = { -1,-1 };
        int point = findOneTarget(nums, target);
        if (point == -1)
            return re;
        int first = findFirst(nums, point, target);
        int last = findLast(nums, point, target);
        re[0] = first;
        re[1] = last;
        return re;
    }
private:
    int findOneTarget(vector<int>& nums, int target) {
        int begin = 0, end = nums.size() - 1, mid;
        bool befind = false;
        while (begin <= end) {
            mid = (begin + end) / 2;
            if (nums[mid] > target)
                end = mid - 1;
            else if (nums[mid] < target)
                begin = mid + 1;
            else {
                befind = true;
                break;
            }
        }
        if (befind)
            return mid;
        return -1;
    }
    int findFirst(vector<int>& nums, int point, int target) {
        int begin = 0, end = point, mid = 0;
        int first = point;
        while (begin <= end) {
            mid = (begin + end) / 2;
            if (nums[mid] < target)
                begin = mid + 1;
            else {
                first = mid;
                end = mid - 1;
            }
        }
        return first;
    }
    int findLast(vector<int>& nums, int point, int target) {
        int begin = point, end = nums.size() - 1, mid = 0;
        int last = point;
        while (begin <= end) {
            mid = (begin + end) / 2;
            if (target < nums[mid])
                end = mid - 1;
            else {
                last = mid;
                begin = mid + 1;
            }
        }
        return last;
    }
};

int main() {
    vector<int> nums = { 5,7,7,8,8,10 };
    Solution sol;
    vector<int> re = sol.searchRange(nums, 8);
    cout << re[0] << " " << re[1];
    return 0;
}