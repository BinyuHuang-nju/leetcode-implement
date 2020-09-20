#include <iostream>
using namespace std;
#include <vector>
#include<string>
#include <cstring>
#include <algorithm>

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int len = s.length();
        vector<string> results, cur;
        dfs(results, cur, s, 0, len, 0);
        return results;
    }
    void dfs(vector<string>& results, vector<string> cur, string s, int start, int len, int depth) {
        if (start == len && depth == 4) {
            string result = cur[0];
            for (int i = 1; i < 4; i++)
                result += "." + cur[i];
            results.push_back(result);
            return;
        }
        if (start == len || depth == 4 || (len - start) > 3 * (4 - depth) || (len - start) < (4 - depth))
            return;
        if (s[start] == '0') {
            cur.push_back("0");
            dfs(results, cur, s, start + 1, len, depth + 1);
            return;
        }
        for (int i = start; i < start + 3 && i < len; i++) {
            string tmp = s.substr(start, i - start + 1);
            if (stoi(tmp) < 256) {
                cur.push_back(tmp);
                dfs(results, cur, s, i + 1, len, depth + 1);
                cur.pop_back();
            }
        }
    }
};
int main() {
    Solution sol;
    //sol.restoreIpAddresses("25525511135");
    //sol.restoreIpAddresses("0000");
    sol.restoreIpAddresses("010010");
    return 0;
}