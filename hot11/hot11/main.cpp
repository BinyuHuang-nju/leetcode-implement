#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <stack>

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else {
                if (st.empty())
                    return false;
                else if (st.top() == '(' && s[i] == ')')
                    st.pop();
                else if (st.top() == '[' && s[i] == ']')
                    st.pop();
                else if (st.top() == '{' && s[i] == '}')
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
    }
};

int main() {
    string str;
    getline(cin, str);
    Solution sol;
    cout << sol.isValid(str);
    return 0;
}