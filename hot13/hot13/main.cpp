#include <iostream>
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    void dfs(vector<string>& re, int left, int right, string cur) {
        if (left == 0 && right == 0)
            re.push_back(cur);
        else {
            if (left > 0)
                dfs(re, left - 1, right + 1, cur + '(');
            if (right > 0)
                dfs(re, left, right - 1, cur + ')');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> re;
        dfs(re, n, 0, "");
        return re;
    }
};
int main() {
    Solution sol;
    int n;
    cin >> n;
    vector<string> re = sol.generateParenthesis(n);
    return 0;
}