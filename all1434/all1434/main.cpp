#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        const long long M = 1e9 + 7;
        vector<vector<int>> match(41);
        for (int i = 0; i < hats.size(); i++) {
            for (int j = 0; j < hats[i].size(); j++)
                match[hats[i][j]].push_back(i);
        }
        int n = hats.size();
        vector<long long> dp(1 << n, 0);
        dp[0] = 1;
        for (int i = 1; i <= 40; i++) {
            if (match[i].empty())
                continue;
            for (int state = (1 << n) - 1; state >= 0; state--) {
                for (int person : match[i]) {
                    if ((1 << person) & state)
                        continue;
                    int next = state + (1 << person);
                    dp[next] = (dp[next] + dp[state]) % M;
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};
int main() {
    Solution sol;
    vector<vector<int>> hats = { {1,2,3,4} ,{1,2,3,4},{1,2,3,4},{1,2,3,4} };
    sol.numberWays(hats);
    return 0;
}