#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <stack>
class Solution {
public:
    string makeGood(string s) {
        int len = s.length();
        if (len < 2)
            return s;
        string result = "";
        stack<bool> st;
        for (int i = 0; i < len; i++) {
            if (result.empty()) {
                result.push_back(s[i]);
                bool is_capital = true;
                if (s[i] >= 'a' && s[i] <= 'z')
                    is_capital = false;
                st.push(is_capital);
            }
            else {
                bool is_capital = false;
                if (s[i] >= 'A' && s[i] <= 'Z')
                    is_capital = true;
                if (is_capital == st.top() || abs(result.back() - s[i]) != 32) {
                    result.push_back(s[i]);
                    st.push(is_capital);
                }
                else {
                    result.pop_back();
                    st.pop();
                }
            }
        }
        return result;
    }
};
int main() {
    Solution sol;
    sol.makeGood("mC");
    return 0;
}