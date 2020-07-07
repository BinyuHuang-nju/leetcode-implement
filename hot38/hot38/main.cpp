#include <iostream>
using namespace std;

class Solution_oldversion {
public:
    int numTrees(int n) {
        return currentNum(1, n);
    }
private:
    int currentNum(int begin, int end) {
        if (end - begin <= 0)
            return 1;
        int num = 0;
        for (int i = begin; i <= end; i++) {
            num = num + currentNum(begin, i - 1) * currentNum(i + 1, end);
        }
        return num;
    }
};
class Solution {
public:
    int numTrees(int n) {
        int* dp = new int[n+1];
        dp[0] = 1;
        dp[1] = 1;
        int i, j;
        for (i = 2; i <= n; i++) {
            dp[i] = 0;
            for (j = 0; j < i; j++)
                dp[i] = dp[i] + dp[j] * dp[i - 1 - j];
        }
        int res = dp[n];
        delete[]dp;
        return res;
    }

};
int main() {
    Solution sol;
    cout << sol.numTrees(3);
    return 0;
}