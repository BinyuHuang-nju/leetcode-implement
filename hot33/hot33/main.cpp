#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(res, cur, nums, 0);
        return res;
    }
private:
    void dfs(vector<vector<int>>& res, vector<int>& cur, vector<int>& nums, int start) {
        res.push_back(cur);
        for (int i = start; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            dfs(res, cur, nums, i + 1);
            cur.pop_back();
        }
    }
};