#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        vector<bool> wasted(s.length(), false);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == ')') {
                if (st.empty())
                    wasted[i] = true;
                else
                    st.pop();
            }
        }
        while (!st.empty()) {
            wasted[st.top()] = true;
            st.pop();
        }
        string result = "";
        for (int i = 0; i < s.length(); i++)
            if (!wasted[i])
                result += s[i];
        return result;
    }
};
int main() {
    Solution sol;
    sol.minRemoveToMakeValid("(a(b(c)d)");
    return 0;
}