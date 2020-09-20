#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
class Solution1 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (k == 0 || nums.size() == 0)
            return res;
        if (nums.size() == 1) {
            res.push_back(nums[0]);
            return res;
        }
        if (k == 1) {
            for (int i = 0; i < nums.size(); i++)
                res.push_back(nums[i]);
            return res;
        }
        int curmax = nums[0], curpos = 0, i, j;
        for (i = 1; i < k; i++)
            if (nums[i] >= curmax) {
                curmax = nums[i];
                curpos = i;
            }
        res.push_back(curmax);
        for (i = k; i < nums.size(); i++) {
            if (i - k + 1 <= curpos) {
                if (curmax > nums[i])
                    res.push_back(curmax);
                else {
                    curmax = nums[i];
                    curpos = i;
                    res.push_back(curmax);
                }
            }
            else {
                curmax = nums[i];
                curpos = i;
                for (j = i - 1; j >= i - k + 1; j--)
                    if (nums[j] > curmax) {
                        curmax = nums[j];
                        curpos = j;
                    }
                res.push_back(curmax);
            }
        }
        return res;
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> results;
        if (k == 0 || nums.size() == 0)
            return results;
        if (k == 1)
            return nums;
        deque<int> queNum;
        queNum.push_back(0);
        int maxPos = 0;
        for (int i = 1; i < k; i++) {
            while (!queNum.empty() && nums[queNum.back()] <= nums[i])
                queNum.pop_back();
            queNum.push_back(i);
        }
        results.push_back(nums[queNum.front()]);
        for (int i = k; i < nums.size(); i++) {
            if (queNum.front() == i - k) {
                queNum.pop_front();
            }
            while (!queNum.empty() && nums[queNum.back()] <= nums[i])
                queNum.pop_back();
            /*if (queNum.empty())
                maxPos = i;*/
            queNum.push_back(i);
            results.push_back(nums[queNum.front()]);
        }
        return results;
    }
};
int main() {
    vector<int> a = { 1,3,1,2,0,5 };
    Solution sol;
    sol.maxSlidingWindow(a, 3);
    return 0;

}