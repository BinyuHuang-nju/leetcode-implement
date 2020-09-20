#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> cur;
        vector<bool> visited(n, false);
        vector<vector<int>> results;
        dfs(results, cur, nums, visited, 0, n);
        return results;
    }
    void dfs(vector<vector<int>>& results, vector<int>& cur, vector<int>& nums, vector<bool>& visited, int start, int n) {
        if (start == n) {
            results.push_back(cur);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (i != 0 && nums[i] == nums[i - 1]&&!visited[i-1])
                    continue;
                cur.push_back(nums[i]);
                visited[i] = true;
                dfs(results, cur, nums, visited, start + 1, n);
                cur.pop_back();
                visited[i] = false;
            }
        }
    }
};
int main() {
    Solution sol;
    vector<int> a = { 1,1,2 };
    sol.permuteUnique(a);
    return 0;
}