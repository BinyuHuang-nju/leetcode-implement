#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <cstring>

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if (s.length() == 0)
            return res;
        vector<string> cur;
        vector<vector<bool>> match(s.length(), vector<bool>(s.length(), false));
        int i, j;
        for (i = s.length() - 1; i >= 0; i--) {
            match[i][i] = true;
            for (j = i + 1; j < s.length(); j++) {
                if (j - i == 1)
                    match[i][j] = (s[i] == s[j]);
                else
                    match[i][j] = match[i + 1][j - 1] && (s[i] == s[j]);
            }
        }
        dfs(res, cur, s, match, 0);
        return res;
    }
    void dfs(vector<vector<string>>& res, vector<string>& cur, string s, \
        vector<vector<bool>>& match, int begin) {
        if (begin == s.length())
            res.push_back(cur);
        else {
            for (int i = begin; i < s.length(); i++) {
                if (match[begin][i]) {
                    cur.push_back(s.substr(begin, i - begin + 1));
                    dfs(res, cur, s, match, i + 1);
                    cur.pop_back();
                }
            }
        }
    }
};