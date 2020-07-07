#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> visited(nums.size(), false);
        vector<int> cur;
        dfs(res, nums, visited, cur, 0);
        return res;
    }
private:
    void dfs(vector<vector<int>>& res, vector<int>& nums, vector<bool>& visited, vector<int>& cur, int depth) {
        if (depth == nums.size())
            res.push_back(cur);
        else {
            for (int i = 0; i < nums.size(); i++) {
                if (!visited[i]) {
                    visited[i] = true;
                    cur.push_back(nums[i]);
                    dfs(res, nums, visited, cur, depth + 1);
                    visited[i] = false;
                    cur.pop_back();
                }
            }
        }
    }
};
int main() {
    vector<int> nums = { 1,2,3,4 };
    Solution sol;
    vector<vector<int>> re = sol.permute(nums);
    return 0;
}