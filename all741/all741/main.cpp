#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution1 {
public: //greed: wrong answer
        //case :[[1,1,1,1,0,0,0],[0,0,0,1,0,0,0],[0,0,0,1,0,0,1],[1,0,0,1,0,0,0],
                    //[0,0,0,1,0,0,0],[0,0,0,1,0,0,0],[0,0,0,1,1,1,1]]
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp1(n, vector<int>(n, -1));
        dp1[0][0] = grid[0][0];
        for (int i = 1; i < n; i++) {
            if (grid[i][0] == -1 || dp1[i - 1][0] == -1)
                continue;
            dp1[i][0] = dp1[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; j++) {
            if (grid[0][j] == -1 || dp1[0][j - 1] == -1)
                continue;
            dp1[0][j] = dp1[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (grid[i][j] == -1 || (dp1[i - 1][j] == -1 && dp1[i][j - 1] == -1))
                    continue;
                dp1[i][j] = max(dp1[i - 1][j], dp1[i][j - 1]) + grid[i][j];
            }
        }
        if (dp1[n - 1][n - 1] <= 0)
            return 0;
        int result = dp1[n - 1][n - 1];
        grid[n - 1][n - 1] = 0;
        int i = n - 1, j = n - 1;
        while (i > 0 || j > 0) {
            if (i == 0 || (j > 0 && dp1[i - 1][j] <= dp1[i][j - 1]))
                j--;
            else
                i--;
            grid[i][j] = 0;
        }
        vector<vector<int>> dp2(n, vector<int>(n, -1));
        dp2[0][0] = grid[0][0];
        for (int i = 1; i < n; i++) {
            if (grid[i][0] == -1 || dp2[i - 1][0] == -1)
                continue;
            dp2[i][0] = dp2[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; j++) {
            if (grid[0][j] == -1 || dp2[0][j - 1] == -1)
                continue;
            dp2[0][j] = dp2[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (grid[i][j] == -1 || (dp2[i - 1][j] == -1 && dp2[i][j - 1] == -1))
                    continue;
                dp2[i][j] = max(dp2[i - 1][j], dp2[i][j - 1]) + grid[i][j];
            }
        }
        result += dp2[n - 1][n - 1];
        return result;
    }
};
class Solution2 { // true but exceeds time limatations.
public: 
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        return max(0, dfs(grid, memo, 0, 0, 0, n));
    }
    int dfs(vector<vector<int>>& grid,vector<vector<vector<int>>>& memo, int r1, int c1, int c2, int n) {
        int r2 = r1 + c1 - c2;
        if (r1 == n || c1 == n || r2 == n || c2 == n || grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return INT_MIN;
        if (r1 == n - 1 && c1 == n - 1)
            return grid[r1][c1];
        if (memo[r1][c1][c2] >= 0)
            return memo[r1][c1][c2];
        int result = grid[r1][c1];
        if (r1 != r2)
            result += grid[r2][c2];
        result += max(max(dfs(grid, memo, r1 + 1, c1, c2, n), dfs(grid, memo, r1 + 1, c1, c2 + 1, n)), \
            max(dfs(grid, memo, r1, c1 + 1, c2 + 1, n), dfs(grid, memo, r1, c1 + 1, c2, n)));
        memo[r1][c1][c2] = result;
        return result;
    }
};
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> memo(n+1, vector<vector<int>>(n+1, vector<int>(n+1, INT_MIN)));
        for (int r1 = n - 1; r1 >= 0; r1--) {
            for (int c1 = n - 1; c1 >= 0; c1--) {
                if (grid[r1][c1] == -1)
                    continue;
                if (r1 == n - 1 && c1 == n - 1) {
                    memo[r1][c1][n - 1] = grid[r1][c1];
                    continue;
                }
                for (int r2 = n - 1; r2 >= 0; r2--) {
                    int c2 = r1 + c1 - r2;
                    if (c2 < 0 || c2 >= n || grid[r2][c2] == -1)
                        continue;
                    int result = grid[r1][c1];
                    if (r1 != r2)
                        result += grid[r2][c2];
                    result += max(max(memo[r1 + 1][c1][r2], memo[r1 + 1][c1][r2 + 1]), \
                        max(memo[r1][c1 + 1][r2 + 1], memo[r1][c1 + 1][r2]));
                    memo[r1][c1][r2] = result;
                }
            }
        }
        return max(0, memo[0][0][0]);
    }
};
int main() {
    Solution sol;
    vector<vector<int>> a = { {0,1,-1},{1,0,-1},{1,1,1} };
    int x = sol.cherryPickup(a);
    return 0;
}