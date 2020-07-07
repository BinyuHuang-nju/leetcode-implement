#include <iostream>
using namespace std;
#include <vector>
#include <stack>

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0);
        int max = 0, cur = 0, top, width;
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                top = st.top();
                st.pop();
                width = st.empty() ? i : i - (st.top() + 1);
                cur = width * heights[top];
                max = cur > max ? cur : max;
            }
            st.push(i);
        }
        return max;
    }
};
int main() {
    vector<int> heights = { 2,1,5,6,2,3 };
    Solution sol;
    cout << sol.largestRectangleArea(heights);
    return 0;
}