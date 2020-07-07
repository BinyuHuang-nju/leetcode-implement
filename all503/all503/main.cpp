#include <iostream>
using namespace std;
#include <vector>
#include <stack>

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        if (nums.size() < 2)
            return res;
        stack<int> st;
        int cur = 0;
        for (int i = 0; i < 2 * nums.size(); i++) {
            cur = nums[i % nums.size()];
            while (!st.empty() && cur > nums[st.top()]) {
                res[st.top()] = cur;
                st.pop();
            }
            if (i < nums.size())
                st.push(i);
        }
        return res;
    }
};
int main() {
    Solution sol;
    vector<int> a = { 1,2,1 };
    vector<int> res = sol.nextGreaterElements(a);
    return 0;
}