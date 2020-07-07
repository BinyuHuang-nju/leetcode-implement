#include <iostream>
using namespace std;
#include <string>

class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length(), i, pre;
        if (len == 0 || len == 1)
            return 0;
        int* dp = new int[len];
        dp[0] = 0;
        for (i = 1; i < len; i++) {
            if (s[i] == '(')
                dp[i] = 0;
            else if (s[i] == ')') {
                pre = i - 1 - dp[i - 1];
                if (pre >= 0 && s[pre] == '(') {
                    dp[i] = dp[i - 1] + 2;
                    if (pre > 0)
                        dp[i] = dp[i] + dp[pre - 1];
                }
                else
                    dp[i] = 0;
            }
        }
        int max = 0;
        for (i = 0; i < len; i++)
            if (dp[i] > max)
                max = dp[i];
        delete[]dp;
        return max;
    }
};

int main() {
    string str;
    getline(cin, str);
    Solution sol;
    cout << sol.longestValidParentheses(str);
    return 0;
}