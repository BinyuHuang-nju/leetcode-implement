#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <cstring>

class Solution1 { // true but exceeds time limitation
public:
    int numDecodings(string s) {
        if (s.length() == 0)
            return 0;
        return sub(s, 0);
    }
    int sub(string s, int begin) {
        if (begin < s.length() && s[begin] == '0')
            return 0;
        if (begin >= s.length() - 1)
            return 1;
        int res = sub(s, begin + 1);
        if (begin < s.length() - 1) {
            if (s[begin] == '1' || (s[begin] == '2' && s[begin + 1] >= '0' && s[begin + 1] <= '6'))
                res += sub(s, begin + 2);
        }
        return res;
    }
};

class Solution {  //pass
public:
    int numDecodings(string s) {
        if (s.length() == 0)
            return 0;
        if (s.length() == 1)
            return s[0] == '0' ? 0 : 1;
        vector<int> dp(s.length() + 1, 0);
        dp[s.length()] = 1;
        dp[s.length() - 1] = (s[s.length() - 1] == '0') ? 0 : 1;
        for (int i = (int)s.length() - 2; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
                continue;
            }
            else {
                dp[i] = dp[i + 1];
                if (s[i] == '1' || (s[i] == '2' && s[i + 1] >= '0' && s[i + 1] <= '6'))
                    dp[i] += dp[i + 2];
            }
        }
        return dp[0];
    }

};