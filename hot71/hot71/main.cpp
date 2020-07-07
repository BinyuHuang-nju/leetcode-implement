#include <iostream>
using namespace std;
#include <math.h>

class Solution {
public:
    int numSquares(int n) {
       /* int num = 0, m;
        while (n > 0) {
            m=(int)sqrt(n);
            n = n - m * m;
            num++;
        }
        return num;*/
        int* dp = new int[n + 1];
        int m, i, j;
        dp[0] = 0;
        dp[1] = 1;
        for (i = 2; i <= n; i++) {
            dp[i] = INT_MAX;
            m = (int)sqrt(i);
            for(j = 1; j <= m; j++)
                if (dp[i - j * j] + 1 < dp[i])
                    dp[i] = dp[i - j * j] + 1;
        }
        int res = dp[n];
        delete[]dp;
        return res;
    }
};