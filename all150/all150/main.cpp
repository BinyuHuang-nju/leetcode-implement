#include <iostream>
using namespace std;
#include <vector>
#include <stack>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int temp1, temp2, result;
        for (string token : tokens) {
            if (token[0] == '+') {
                temp1 = st.top();
                st.pop();
                temp2 = st.top();
                st.pop();
                result = temp1 + temp2;
                st.push(result);
            }
            else if (token.length()==1 && token[0] == '-') {
                temp1 = st.top();
                st.pop();
                temp2 = st.top();
                st.pop();
                result = temp2 - temp1;
                st.push(result);
            }
            else if (token[0] == '*') {
                temp1 = st.top();
                st.pop();
                temp2 = st.top();
                st.pop();
                result = temp1 * temp2;
                st.push(result);
            }
            else if (token[0] == '/') {
                temp1 = st.top();
                st.pop();
                temp2 = st.top();
                st.pop();
                result = temp2 / temp1;
                st.push(result);
            }
            else {
                result = atoi(token.c_str());
                st.push(result);
            }
        }
        return st.top();
    }
};
int main() {
    vector<string> a = { "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
    Solution sol;
    cout << sol.evalRPN(a);
    return 0;
}