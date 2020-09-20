#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
private:
    int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] > 0) {
                    int neighbors = 0, newi, newj;
                    for (int k = 0; k < 4; k++) {
                        newi = i + dir[k][0];
                        newj = j + dir[k][1];
                        if (newi < 0 || newi >= grid.size() || newj < 0 || newj >= grid[0].size() || grid[newi][newj] == 0)
                            continue;
                        neighbors++;
                    }
                    if (neighbors == 0)
                        result = max(result, grid[i][j]);
                    else {  // sometimes there is no leaf in a graph
                        grid[i][j] = -grid[i][j];
                        dfs(grid, i, j, -grid[i][j], result);
                        grid[i][j] = -grid[i][j];
                    }
                }
            }
        }
        return result;
    }
    void dfs(vector<vector<int>>& grid, int x, int y, int partmax, int& result) {
        bool end = true;
        for (int k = 0; k < 4; k++) {
            int newx = x + dir[k][0], newy = y + dir[k][1];
            if (newx < 0 || newx >= grid.size() || newy < 0 || newy >= grid[0].size() || grid[newx][newy] <= 0)
                continue;
            end = false;
            partmax += grid[newx][newy];
            grid[newx][newy] = -grid[newx][newy];
            dfs(grid, newx, newy, partmax, result);
            grid[newx][newy] = -grid[newx][newy];
            partmax -= grid[newx][newy];
        }
        if (end) {
            result = max(result, partmax);
        }
    }
};

int main() {
    Solution sol;
    //vector<vector<int>> a = { {0,6,0},{5,8,7},{0,9,0} };
   // vector<vector<int>> a = { {1,0,7},{2,0,6},{3,4,5},{0,3,0},{9,0,20} };
    vector<vector<int>> a = { {23, 21, 38, 12, 18, 36, 0, 7, 30, 29, 20, 3, 28 }, { 23, 3, 19, 2, 1, 11, 4, 8, 9, 24, 6, 5, 35 }};
    sol.getMaximumGold(a);
    return 0;
}