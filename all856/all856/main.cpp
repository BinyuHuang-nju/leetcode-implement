#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <stack>

class Solution {
private:
    struct Tag {
        bool isLeftBracket;
        int digit;
        Tag() :isLeftBracket(true), digit(0) {}
    };
public:
    int scoreOfParentheses(string S) {
        if (S.length() == 0)
            return 0;
        stack<Tag> st;
        Tag left;
        left.isLeftBracket = true;
        Tag num;
        num.isLeftBracket = false;
        Tag temp;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == '(')
                st.push(left);
            else {
                if (!st.empty() && st.top().isLeftBracket) {
                    st.pop();
                    num.digit = 1;
                    st.push(num);
                }
                else {
                    int cur = 0;
                    while (!st.empty()) {
                        temp = st.top();
                        st.pop();
                        if (!temp.isLeftBracket) {
                            cur = cur + temp.digit;
                        }
                        else {
                            num.digit = 2 * cur;
                            st.push(num);
                            break;
                        }
                    }
                }
            }
        }
        int result = 0;
        while (!st.empty()) {
            result = result + st.top().digit;
            st.pop();
        }
        return result;
    }
};