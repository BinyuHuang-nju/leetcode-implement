#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        string result = "";
        for (int i = 0; i < strs[0].length(); i++) {
            char pivot = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (i == strs[j].length() || pivot != strs[j][i])
                    return result;
            }
            result += pivot;
        }
        return result;
    }
};
int main() {
    Solution sol;
    vector<string> ss = { "flower","flow","flight" };
    string reuslt = sol.longestCommonPrefix(ss);
    return 0;
}