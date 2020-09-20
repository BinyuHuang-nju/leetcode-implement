#include <iostream>
using namespace std;
#include <vector>
#include <stack>
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int depth = 1, cur = label;
        stack<int> st;
        st.push(label);
        while (cur > 1) {
            cur /= 2;
            st.push(cur);
            depth++;
        }
        vector<int> results;
        int cur_depth = 1;
        while (!st.empty()) {
            if (cur_depth == 1 || (depth-cur_depth)%2==0) {
                results.push_back(st.top());
            }
            else {
                int s = pow(2, cur_depth - 1), b = 2*s - 1;
                results.push_back(s + b - st.top());
            }
            st.pop();
            cur_depth++;
        }
        return results;
    }
};