#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <cstring>

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        int i, j;
        string sub;
        bool exist;
        for (i = 1; i <= s.length(); i++) {
            for (j = 0; j < i; j++) {
                if (dp[j]) {
                    sub = s.substr(j, i - j);
                    exist = false;
                    for (int k = 0; k < wordDict.size(); k++)
                        if (sub == wordDict[k]) {
                            exist = true;
                            break;
                        }
                    if (exist) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.length()];
    }
};