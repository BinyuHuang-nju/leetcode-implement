#include <iostream>
using namespace std;
#include <vector>

class Solution {
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
        for(i=1;i<k;i++)
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
                for(j=i-1;j>=i-k+1;j--)
                    if(nums[j]>curmax){
                        curmax = nums[j];
                        curpos = j;
                    }
                res.push_back(curmax);
            }
        }
        return res;
    }
};