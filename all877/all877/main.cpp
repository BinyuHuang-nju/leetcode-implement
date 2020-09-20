#include <iostream>
using namespace std;
#include <vector>
#include <cmath>
#include <algorithm>
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int len = piles.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        int i, j;
        for (i = 0; i < len; i++)
            dp[i][i] = piles[i];
        for (i = 0; i < len - 1; i++)
            dp[i][i + 1] = abs(piles[i] - piles[i + 1]);
        for (i = len - 3; i >= 0; i--) {
            for (j = i + 2; j < len; j++) {
                dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
            }
        }
        return dp[0][len - 1];
    }

};