#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string result;
        int total_bracket = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '(' && s[i] != ')') {
                result += s[i];
            }
            else if (s[i] == '(') {
                st.push(i - total_bracket);
                total_bracket++;
            }
            else {
                total_bracket++;
                reverse(result.begin() + st.top(), result.end());
                st.pop();
            }
        }
        return result;
    }
};
int main() {
    string a = "a(bcdefghijkl(mno)p)q";
    Solution sol;
    string re = sol.reverseParentheses(a);
    cout << re;
    return 0;
}
