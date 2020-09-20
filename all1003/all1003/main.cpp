#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <stack>

class Solution {
public:
    bool isValid(string S) {
        if (!S.length())
            return true;
        stack<char> st;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == 'a') {
                st.push(S[i]);
            }
            else if (S[i] == 'b') {
                if (st.empty() || st.top() != 'a')
                    return false;
                st.push(S[i]);
            }
            else if (S[i] == 'c') {
                if (st.empty() || st.top() != 'b')
                    return false;
                st.pop();
                if (st.empty() || st.top() != 'a')
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};