#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if (n <= k)
            return res;
        vector<int> cur;
        dfs(res, cur, n, k, 1);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int>& cur, int target, int remain, int begin) {
        if (target == 0 && remain == 0)
            res.push_back(cur);
        else if (target == 0 || remain == 0)
            return;
        else {
            for (int i = begin; i <= 9; i++) {
                if (target >= i) {
                    cur.push_back(i);
                    dfs(res, cur, target - i, remain - 1, i + 1);
                    cur.pop_back();
                }
            }
        }
    }
};