#include <iostream>
using namespace std;
#include <stack>
#include <string>
#include <vector>

class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> st;
        for (int i = 0; i < S.length(); i++) {
            if (st.empty() || S[i] == '(' || st.top() == ')')
                st.push(S[i]);
            else if (S[i] == ')' && st.top() == '(')
                st.pop();
        }
        return st.size();
    }
};