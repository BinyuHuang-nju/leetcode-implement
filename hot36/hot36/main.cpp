#include <iostream>
using namespace std;
#include <vector>
#include <stack>

class Solution {
public: //stack+dp
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0)
            return 0;
        else if (matrix[0].size() == 0)
            return 0;
        vector<int> heights(matrix[0].size(), 0);
        int max = 0, cur;
        int i, j;
        for (i = 0; i < matrix.size(); i++) {
            for (j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '0')
                    heights[j] = 0;
                else
                    heights[j] = heights[j] + 1;
            }
            cur = largestRectangleArea(heights);
            max = max > cur ? max : cur;
        }
        return max;
    }
private:
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
    vector<vector<char>> matrix = { {'1','0','1','0','0'},{'1','0','1','1','1'}, {'1','1','1','1','1'}, {'1','0','0','1','0'} };
    Solution sol;
    cout << sol.maximalRectangle(matrix);
    return 0;
}