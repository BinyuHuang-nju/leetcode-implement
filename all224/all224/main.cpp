#include <iostream>
using namespace std;
#include <stack>
#include <string>
#include <cstring>
#include <vector>

 // atoi:stirng->int ; to_string: int->string
class Solution {
public:
    int calculate(string s) {
        s = "(" + s + ")";
        stack<string> st;
        int i = 0, j, temp, cur;
        while(i < s.length()) {
            if (s[i] == ' ')
                i++;
            else if (s[i] == '(' || s[i] == '+' || s[i] == '-') {
                st.push(s.substr(i, 1));
                i++;
            }
            else if (s[i] == ')') {
                stack<int> digits;
                while (!st.empty()) {
                    if (st.top() == "+") {
                        st.pop();
                    }
                    else if (st.top() == "-") {
                        temp = digits.top();
                        digits.pop();
                        temp = -temp;
                        digits.push(temp);
                        st.pop();
                    }
                    else if (st.top() == "(") {
                        cur = 0;
                        while (!digits.empty()) {
                            cur = cur + digits.top();
                            digits.pop();
                        }
                        st.pop();
                        st.push(to_string(cur));
                        break;
                    }
                    else {
                        digits.push(atoi(st.top().c_str()));
                        st.pop();
                    }
                }
                i++;
            }
            else {
                j = i;
                cur = 0;
                while (j < s.length() && s[j] >= '0' && s[j] <= '9') {
                    j++;
                }
                st.push(s.substr(i, j - i));
                i = j;
                /*
                while (j < s.length() && s[j] >= '0' && s[j] <= '9') {
                    cur = cur * 10 + (s[j] - '0');
                    j++;
                }
                if (st.empty())
                    st.push(s.substr(i, j - i));
                else if (st.top() == "+") {
                    st.pop();
                    temp = atoi(st.top().c_str());
                    st.pop();
                    cur = temp + cur;
                    st.push(to_string(cur));
                }
                else if (st.top() == "-") {
                    st.pop();
                    temp = atoi(st.top().c_str());
                    st.pop();
                    cur = temp - cur;
                    st.push(to_string(cur));
                }
                else
                    st.push(s.substr(i, j - i));
                i = j;*/
            }
        }

        return atoi(st.top().c_str());
    }
};
int main() {
    string s = "(1 +( 4+5+ 2)-3)+( 6+8)";
    Solution sol;
    cout << sol.calculate(s);
    return 0;
}