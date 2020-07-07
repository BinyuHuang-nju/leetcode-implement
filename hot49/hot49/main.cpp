#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dic(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        int i, j;
        for (i = 1; i <= s.size(); i++) {
            for (j = 0; j < i; j++) {
                if (dp[j] == true && dic.find(s.substr(j, i - j)) != dic.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};