#include <iostream>
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    int minCut(string s) {
        if (s.length() <= 1)
            return 0;
        vector<vector<bool>> match(s.length(), vector<bool>(s.length(), false));
        int i, j;
        for (i = 0; i < s.length(); i++)
            match[i][i] = true;
        for (i = s.length() - 2; i >= 0; i--) {
            for (j = i + 1; j < s.length(); j++) {
                if (j - i == 1)
                    match[i][j] = (s[i] == s[j]);
                else
                    match[i][j] = match[i + 1][j - 1] && (s[i] == s[j]);
            }
        }
        vector<int> cut(s.length(), s.length());
        for (i = 0; i < s.length(); i++) {
            if (match[0][i])
                cut[i] = 1;
            else {
                for (j = 1; j <= i; j++)
                    if (match[j][i])
                        cut[i] = min(cut[i], cut[j - 1] + 1);
            }
        }
        return cut[s.length() - 1] - 1;
    }
    int min(int x, int y) {
        return x < y ? x : y;
    }
};