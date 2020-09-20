#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution1 { //true but exceeds time limitations 128/131
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        if (n < 2) return 0;
        vector<int> presum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            presum[i] = presum[i - 1] + stoneValue[i - 1];
        }
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 1; i--) {
            for (int j = i + 1; j <= n; j++) {
                for (int mid = i; mid < j; mid++) {
                    int bef = presum[mid] - presum[i - 1], beh = presum[j] - presum[mid];
                    if (bef < beh)
                        dp[i][j] = max(dp[i][j], dp[i][mid] + bef);
                    else if (bef > beh)
                        dp[i][j] = max(dp[i][j], dp[mid + 1][j] + beh);
                    else
                        dp[i][j] = max(dp[i][j], max(dp[i][mid], dp[mid + 1][j]) + bef);
                }
            }
        }
        return dp[1][n];
    }
};
class Solution2 {  //pass
public:
    vector<vector<int>> memo;
    vector<int> presum;
    vector<int> stone;
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        if (n < 2) return 0;
        presum = vector<int>(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            presum[i] = presum[i - 1] + stoneValue[i - 1];
        }
        memo = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
        stone = stoneValue;
        return dfs(1, n);
    }
    int dfs(int i, int j) {
        if (i >= j || memo[i][j] != 0)
            return memo[i][j];
        int bef = stone[i-1], beh = presum[j] - presum[i], mid;
        for (mid = i; mid < j && bef < beh; mid++) {
            memo[i][j] = max(memo[i][j], dfs(i, mid) + bef);
            bef += stone[mid];
            beh -= stone[mid];
        }
        if (bef == beh) {
            memo[i][j] = max(memo[i][j], max(dfs(i, mid), dfs(mid + 1, j)) + bef);
            bef += stone[mid];
            beh -= stone[mid];
            mid++;
        }
        for (; mid < j; mid++) {
            memo[i][j] = max(memo[i][j], dfs(mid + 1, j) + beh);
            beh -= stone[mid];
        }
        return memo[i][j];
    }
};
class Solution3 { //true but exceeds time limitations 130/131
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        if (n < 2) return 0;
        vector<int> presum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            presum[i] = presum[i - 1] + stoneValue[i - 1];
        }
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 1; i--) {
            for (int j = i + 1; j <= n; j++) {
                int bef = stoneValue[i - 1], beh = presum[j] - presum[i], mid;
                for (mid = i; mid < j && bef < beh; mid++) {
                    dp[i][j] = max(dp[i][j], dp[i][mid] + bef);
                    bef += stoneValue[mid];
                    beh -= stoneValue[mid];
                }
                if (bef == beh) {
                    dp[i][j] = max(dp[i][j], max(dp[i][mid], dp[mid + 1][j]) + bef);
                    bef += stoneValue[mid];
                    beh -= stoneValue[mid];
                    mid++;
                }
                for (; mid < j; mid++) {
                    dp[i][j] = max(dp[i][j], dp[mid + 1][j] + beh);
                    beh -= stoneValue[mid];
                }
            }
        }
        return dp[1][n];
    }
};
class Solution { 
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        if (n < 2) return 0;
        vector<int> presum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            presum[i] = presum[i - 1] + stoneValue[i - 1];
        }
        vector<vector<int>> pos(n + 1, vector<int>(n + 1, 0));
        for (int i = n; i >= 1; i--) {
            pos[i][i] = i - 1;
            for (int j = i + 1; j <= n; j++) {
                int newpos = pos[i][j - 1];
                while (newpos < j && presum[newpos+1] - presum[i - 1] <= presum[j] - presum[newpos + 1])
                    newpos++;
                pos[i][j] = newpos;
            }
        }
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        vector<vector<int>> optl(n + 1, vector<int>(n + 1, 0));
        vector<vector<int>> optr(n + 1, vector<int>(n + 1, 0));
        for (int i = n; i >= 1; i--) {
            optl[i][i] = optr[i][i] = stoneValue[i - 1];
            for (int j = i + 1; j <= n; j++) {
                int curpos = pos[i][j];
                if (curpos < i) {
                    dp[i][j] = optl[i + 1][j];
                }
                else if (presum[curpos] - presum[i - 1] == presum[j] - presum[curpos]) {
                    dp[i][j] = max(optl[i][curpos], optr[curpos + 1][j]);
                }
                else {
                    dp[i][j] = optl[i][curpos];
                    if(curpos+1<j)
                        dp[i][j] = max(dp[i][j], optr[curpos + 2][j]);
                }

                optl[i][j] = max(dp[i][j] + presum[j] - presum[i - 1], optl[i][j - 1]);
                optr[i][j] = max(dp[i][j] + presum[j] - presum[i - 1], optr[i + 1][j]);
            }
        }
        return dp[1][n];
    }
};
int main() {
    Solution sol;
    vector<int> a = { 9,8,2,4,6,3,5,1,7 };
    int x= sol.stoneGameV(a);
    return 0;
}