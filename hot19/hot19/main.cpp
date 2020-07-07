#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        checkSum(res, candidates, target, 0, cur, 0);
        return res;
    }
private:
    void checkSum(vector<vector<int>>& res, vector<int>& candidates, int target, int cursum, vector<int> cur, int begin) {
        if (cursum == target)
            res.push_back(cur);
        else {
            for(int i=begin;i<candidates.size();i++)
                if (candidates[i] + cursum <= target) {
                    cur.push_back(candidates[i]);
                    checkSum(res, candidates, target, cursum + candidates[i], cur, i);
                    cur.pop_back();
                }
        }
    }
};