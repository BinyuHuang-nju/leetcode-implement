#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if (candidates.size() == 0)
            return res;
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        checkSum(res, candidates, cur, target, 0, 0);
        return res;
    }
    void checkSum(vector<vector<int>>& res, vector<int>& candidates, \
        vector<int>& cur, int target, int cursum, int begin) {
        if (cursum == target)
            res.push_back(cur);
        else {
            for (int i = begin; i < candidates.size(); i++) {
                if (i != begin && candidates[i] == candidates[i - 1])
                    continue;
                if (cursum + candidates[i] <= target) {
                    cur.push_back(candidates[i]);
                    checkSum(res, candidates, cur, target, cursum + candidates[i], i + 1);
                    cur.pop_back();
                }
            }
        }
    }
};