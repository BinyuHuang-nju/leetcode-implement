#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution1 {  //true , but exceeds time limitation
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() < 2)
            return nums;
        sort(nums.begin(), nums.end());
        vector<int> res, cur;
        dfs(res, nums, 0, 1, cur);
        return res;
    }
    void dfs(vector<int>& res, vector<int>& nums, int begin ,int last,vector<int>& cur) {
        bool isEnd = true;
        for (int i = begin; i < nums.size(); i++) {
            if (nums[i] % last == 0) {
                isEnd = false;
                cur.push_back(nums[i]);
                dfs(res, nums, i + 1, nums[i], cur);
                cur.pop_back();
            }
        }
        if (isEnd) {
            if (res.size() < cur.size())
                res.assign(cur.begin(), cur.end());
        }
    }
};

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() < 2)
            return nums;
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1);
        int i, j;
        int maxnum = 1, index = 0;
        for (i = 1; i < nums.size(); i++) {
            for (j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0)
                    dp[i] = dp[i] > dp[j] + 1 ? dp[i] : (dp[j] + 1);
            }
            if (dp[i] > maxnum) {
                maxnum = dp[i];
                index = i;
            }
        }
        vector<int> res;
        for (i = index; i >= 0; i--) {
            if (dp[i] == maxnum && nums[index] % nums[i] == 0) {
                res.push_back(nums[i]);
                maxnum--;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> a = { 1,2,3,4,8,9,15,16 };
    vector<int> b = sol.largestDivisibleSubset(a);
    return 0;
}