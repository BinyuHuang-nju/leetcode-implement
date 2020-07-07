#include <iostream>
using namespace std;
#include <vector>
#include <stack>

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3)
            return false;
        int second = INT_MIN;
        stack<int> third;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < second)
                return true;
            while (!third.empty() && third.top() < nums[i]) {
                second = third.top();
                third.pop();
            }
            third.push(nums[i]);
        }
        return false;
    }
};