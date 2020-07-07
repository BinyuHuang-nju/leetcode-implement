#include <iostream>
using namespace std;
#include <string>

class Solution {
public:
    int minDistance(string word1, string word2) {
        int i, j;
        int len1 = word1.length(), len2 = word2.length();
        int** dp = new int* [len1 + 1];
        for (i = 0; i <= len1; i++)
            dp[i] = new int[len2 + 1];
        dp[0][0] = 0;
        for (i = 1; i <= len1; i++)
            dp[i][0] = i;
        for (j = 1; j <= len2; j++)
            dp[0][j] = j;
        for(i=1;i<=len1;i++)
            for (j = 1; j <= len2; j++) {
                dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i][j - 1] + 1 : dp[i - 1][j] + 1;
                if (word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i][j] > dp[i - 1][j - 1] ? dp[i - 1][j - 1] : dp[i][j];
                else
                    dp[i][j] = dp[i][j] > dp[i - 1][j - 1] + 1 ? dp[i - 1][j - 1] + 1 : dp[i][j];
            }
        int res = dp[len1][len2];
        delete[]dp;
        return res;
    }
};
int main() {
    string str1 = "intention", str2 = "execution";
    Solution sol;
    cout << sol.minDistance(str1, str2);
    return 0;
}