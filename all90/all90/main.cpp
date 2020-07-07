#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> cur;
        dfs(res, cur, nums, 0);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int>& cur, vector<int>& nums, int begin) {
        res.push_back(cur);
        for (int i = begin; i < nums.size(); i++) {
            if (i >= begin + 1 && nums[i] == nums[i - 1])
                continue;
            cur.push_back(nums[i]);
            dfs(res, cur, nums, i + 1);
            cur.pop_back();
        }
    }
};