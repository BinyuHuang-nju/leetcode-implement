#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int& a, int& b) {return a > b; });
        int sum = 0;
        for (int num : nums)
            sum += num;
        int target = sum / 2, cur = 0;
        vector<int> results;
        for (int num : nums) {
            cur += num;
            results.push_back(num);
            if (cur > target)
                break;
        }
        return results;
    }
};