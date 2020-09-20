#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
class Solution {
public:
    string countAndSay(int n) {
        vector<string> appearance(n);
        appearance[0] = "1";
        for (int i = 1; i < n; i++) {
            int curlen = 0, len = appearance[i - 1].length();
            for (int j = 0; j <= len; j++) {
                if (j == len || (curlen > 0 && appearance[i - 1][j] != appearance[i - 1][j - 1])) {
                    appearance[i] += to_string(curlen) + appearance[i - 1][j - 1];
                    curlen = 0;
                }
                curlen++;
            }
        }
        return appearance[n - 1];
    }
};
int main() {
    Solution sol;
    sol.countAndSay(5);
    return 0;
}