#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <stack>
class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int result = 0, len = s.length();
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') {
                st.push('(');
                continue;
            }
            // s[i] == ')'
            if (i == len - 1 || s[i + 1] != ')') {
                if (st.empty())
                    result += 2;
                else {
                    result += 1;
                    st.pop();
                }
            }
            else {
                if (st.empty())
                    result += 1;
                else {
                    st.pop();
                }
                i++;
            }
        }
        return result + 2 * st.size();
    }
};
int main() {
    Solution sol;
    sol.minInsertions("(()))");
    return 0;
}