#include <iostream>
using namespace std;
#include <vector>
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int num = 0, i, j;
        for (i = 0; i < grid.size(); i++) {
            for (j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(grid, visited, i, j);
                    num++;
                }
            }
        }
        return num;
    }
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        visited[x][y] = true;
        if (x > 0 && grid[x - 1][y] == '1' && !visited[x - 1][y])
            dfs(grid, visited, x - 1, y);
        if (y > 0 && grid[x][y - 1] == '1' && !visited[x][y - 1])
            dfs(grid, visited, x, y - 1);
        if (x < grid.size() - 1 && grid[x + 1][y] == '1' && !visited[x + 1][y])
            dfs(grid, visited, x + 1, y);
        if (y < grid[0].size() - 1 && grid[x][y + 1] == '1' && !visited[x][y + 1])
            dfs(grid, visited, x, y + 1);
    }
};