#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        int maxlen = 0, i, j;
        int len1 = matrix.size(), len2 = matrix[0].size();
        int** dp = new int* [len1];
        for (i = 0; i < matrix.size(); i++)
            dp[i] = new int[len2];
        //memset(dp, 0, sizeof(int) * len1 * len2);
        for (i = 0; i < len1; i++) {
            if (matrix[i][0] == '1') {
                dp[i][0] = 1;
                maxlen = 1;
            }
            else
                dp[i][0] = 0;
        }
        for (j = 1; j < len2; j++) {
            if (matrix[0][j] == '1') {
                dp[0][j] = 1;
                maxlen = 1;
            }
            else
                dp[0][j] = 0;
        }
        for(i=1;i<len1;i++)
            for (j = 1; j < len2; j++) {
                if (matrix[i][j] == '1') {
                    int tmp = dp[i - 1][j - 1] > dp[i - 1][j] ? dp[i - 1][j] : dp[i - 1][j - 1];
                    dp[i][j] = 1 + (tmp > dp[i][j - 1] ? dp[i][j - 1] : tmp);
                    if (dp[i][j] > maxlen)
                        maxlen = dp[i][j];
                }
                else
                    dp[i][j] = 0;
            }
        delete[]dp;
        return maxlen * maxlen;
    }
};
int main() {
    vector<vector<char>> a = { {'1','0','1','0','0'},{'1','0','1','1','1'}, {'1','1','1','1','1'}, {'1','0','0','1','0'} };
    Solution sol;
    cout << sol.maximalSquare(a);
    return 0;
}