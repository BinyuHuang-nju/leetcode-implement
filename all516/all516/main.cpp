#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <cstring>

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), 1));
        int i, j;
        for (i = s.length() - 2; i >= 0; i--) {
            for (j = i + 1; j < s.length(); j++) {
                if (j - i == 1)
                    dp[i][j] = (s[i] == s[j]) ? 2 : 1;
                else {
                    if (s[i] == s[j])
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    else
                        dp[i][j] = dp[i + 1][j] > dp[i][j - 1] ? dp[i + 1][j] : dp[i][j - 1];
                }
            }
        }
        return dp[0][s.length() - 1];
    }
};