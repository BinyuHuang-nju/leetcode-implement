#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        /*
        queue<int> que;
        int i;
        for (i = 0; i < nums.size(); i++)
            if (nums[i] == 0)
                que.push(i);
        if (que.empty())
            return;
        int cur = 0, num = que.size();
        for (i = 0; i < nums.size()-num; i++) {
            if (!que.empty() && que.front() == i) {
                cur++;
                que.pop();
            }
            nums[i] = nums[i + cur];
        }
        for (i = nums.size() - num; i < nums.size(); i++)
            nums[i] = 0;*/
        int i, cur = 0;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                cur++;
            else
                nums[i - cur] = nums[i];
        }
        for (i = nums.size() - cur; i < nums.size(); i++)
            nums[i] = 0;
    }
};