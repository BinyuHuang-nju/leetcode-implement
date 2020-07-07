#include <iostream>
using namespace std;
#include <vector>
#include <set>

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> res;
        if (nums.size() < 2)
            return vector<vector<int>>(res.begin(), res.end());
        vector<int> cur;
        dfs(nums, res, cur, 0);
        return vector<vector<int>>(res.begin(), res.end());
    }
    void dfs(vector<int>& nums, set<vector<int>>& res, vector<int>& cur, int begin) {
        if (cur.size() >= 2)
            res.insert(cur);
        for (int i = begin; i < nums.size(); i++) {
            if (cur.size() != 0 && nums[i] < cur.back())
                continue;
            cur.push_back(nums[i]);
            dfs(nums, res, cur, i + 1);
            cur.pop_back();
        }
    }
};
int main() {
    Solution sol;
    vector<int> a = { 4,6,7,7 };
    vector<vector<int>> res = sol.findSubsequences(a);
    return 0;
}