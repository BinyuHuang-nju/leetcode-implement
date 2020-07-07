#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <cstring>

class Solution_false {  //exceeds time limitation
public:
    int numDistinct(string s, string t) {
        int num = 0;
        son_pattern(num, s, t, 0, 0);
        return num;
    }
    void son_pattern(int& num, string s, string t, int scur, int tcur) {
        if (tcur == t.length())
            num++;
        else {
            int i = scur;
            while (i < s.length() && s[i] != t[tcur])
                i++;
            if (i == s.length())
                return;
            else {
                son_pattern(num, s, t, i + 1, tcur + 1);
                son_pattern(num, s, t, i + 1, tcur);
            }
        }
    }
};

class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.length() < t.length())
            return 0;
        vector<vector<unsigned int>> dp(s.length() + 1, vector<unsigned int>(t.length() + 1, 0));
        int i, j;
        for (i = 0; i <= s.length(); i++)
            dp[i][0] = 1;
        for (i = 1; i <= s.length(); i++) {
            for (j = 1; j <= t.length(); j++) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return (int)dp[s.length()][t.length()];
    }
};