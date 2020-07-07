#include <iostream>
using namespace std;
#include <string>
#include <cstring>

class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.length(), plen = p.length(), i, j;
        bool** match = new bool* [slen+1];
        for (i = 0; i <= slen; i++)
            match[i] = new bool[plen+1];
        match[0][0] = true;
        for (j = 1; j <= plen; j++) {
            if (p[j - 1] == '*')
                match[0][j] = match[0][j - 2];
            else
                match[0][j] = false;
        }
        for (i = 1; i <= slen; i++)
            match[i][0] = false;
        for (i = 1; i <= slen; i++) {
            for (j = 1; j <= plen; j++) {
                if (p[j - 1] == '*')
                    match[i][j] = match[i][j - 2] || (match[i - 1][j] && (p[j - 2] == '.' || s[i - 1] == p[j - 2]));
                else
                    match[i][j] = match[i - 1][j - 1] && (p[j - 1] == '.' || s[i - 1] == p[j - 1]);
            }
        }
        bool re = match[slen][plen];
        delete[]match;
        return re;
    }
};
int main() {
    string s, p;
    getline(cin, s);
    getline(cin, p);
    Solution sol;
    cout << sol.isMatch(s, p);
    return 0;
}