#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);
        for (int i = 1; i * i <= n; i++)
            dp[i * i] = true;
        int bound = 0;
        for (int i = 1; i <= n; i++) {
            if (dp[i] == true) {
                bound++;
                continue;
            }
            for (int j = 1; j <= bound; j++) {
                if (dp[i - j * j] == false) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
int main() {
    Solution sol;
    sol.winnerSquareGame(7);
    return 0;
}