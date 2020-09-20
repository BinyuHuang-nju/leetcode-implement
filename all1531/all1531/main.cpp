#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.length();
        if (n <= k)
            return 0;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX >> 1));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if (j > 0)
                    dp[i][j] = dp[i - 1][j - 1];  //µÚi¸ö×Ö·û±»É¾³ý
                int same = 0, diff = 0;
                for (int i0 = i; i0 >= 1 && diff <= j; i0--) {
                    if (s[i0 - 1] == s[i - 1]) {
                        same++;
                        dp[i][j] = min(dp[i][j], dp[i0 - 1][j - diff] + calculate(same));
                    }
                    else
                        diff++;
                }
            }
        }
        return dp[n][k];
    }
    int calculate(int len) {
        if (len == 1)
            return 1;
        if (len < 10)
            return 2;
        if (len < 100)
            return 3;
        return 4;
    }
};

int main() {
    Solution sol;
    sol.getLengthOfOptimalCompression("aaabcccd", 2);
    return 0;
}