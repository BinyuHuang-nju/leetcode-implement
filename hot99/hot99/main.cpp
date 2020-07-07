#include <iostream>
using namespace std;
#include <vector>
#include <string>
class Solution {
public:
    int countSubstrings(string s) {
        int sl = s.length(), i, j;
        if (sl < 2)
            return sl;
        vector<vector<bool>> sub(sl, vector<bool>(sl, false));
        for (i = 0; i < sl; i++)
            sub[i][i] = true;
        int res = sl;
        for (i = 0; i < sl - 1; i++) {
            sub[i][i + 1] = (s[i] == s[i + 1]);
            res += sub[i][i + 1];
        }
        for (i = sl - 2; i >= 0; i--) {
            for (j = i + 2; j < sl; j++) {
                if (sub[i + 1][j - 1] && s[i] == s[j]) {
                    sub[i][j] = true;
                    res++;
                }
            }
        }
        return res;
    }
};
int main() {
    string s = "abcaaa";
    Solution sol;
    cout << sol.countSubstrings(s);
    return 0;
}