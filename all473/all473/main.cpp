#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
private:
    static bool cmp(int a, int b) {
        return a > b ? true : false;
    }
public:
    bool makesquare(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        if (nums.size() < 4)
            return false;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum = sum + nums[i];
        if (sum % 4 != 0)
            return false;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                if (!dfs(nums, i, sum / 4))
                    return false;
        }
        return true;
    }
    bool dfs(vector<int>& nums, int begin,int sum) {
        if (sum == 0)
            return true;
        for (int i = begin; i < nums.size(); i++) {
            if (nums[i] > sum)
                continue;
            if (nums[i] > 0) {
                nums[i] = -nums[i];
                if (dfs(nums, i + 1, sum + nums[i]))
                    return true;
                nums[i] = -nums[i];
            }
        }
        return false;
    }
};