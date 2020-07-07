/*
0 0      0            偶变奇 +1
1 01   1             奇变偶  偶是2次幂:1    pow*2
2 010 1                           偶不是2次幂   x-pow是偶
3 011 2
4 100 1
5 101 2
6 110 2 *
7 111 3
8 1000 1
9 1001 2
10 1010 2 *
11 1011 3
12 1100 2 *
13 1101 3
14 1110 3 *
15 1111 4
16 10000 1
*/
#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> countBits(int num) {
        if (num == 0)
            return { 0 };
        if (num == 1)
            return { 0,1 };
        if (num == 2)
            return { 0,1,1 };
        int pow = 2, i;
        int* dp = new int[num + 1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        vector<int>res = { 0,1,1 };
        for (i = 3; i <= num; i++) {
            if (i % 2 == 1)
                dp[i] = dp[i - 1] + 1;
            else if (i == pow * 2) {
                dp[i] = 1;
                pow = pow * 2;
            }
            else {
                dp[i] = dp[i - 1] + (dp[i - pow] - dp[i - pow - 1]);
            }
            res.push_back(dp[i]);
        }
        return res;
    }
};