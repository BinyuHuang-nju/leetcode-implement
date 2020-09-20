#include <iostream>
using namespace std;
#include <vector>

class Solution {
private:
    int direction[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int total = 0;
        int start_i = 0, start_j = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    start_i = i;
                    start_j = j;
                    total++;
                }
                else if (grid[i][j] == 0)
                    total++;
            }
        }
        return dfs(grid, start_i, start_j, total);
    }
private:
    int dfs(vector<vector<int>>& grid, int starti, int startj, int remain) {
        if (starti < 0 || starti >= grid.size() || startj < 0 || startj >= grid[0].size() || grid[starti][startj] == -1)
            return 0;
        if (grid[starti][startj] == 2)
            return remain == 0 ? 1 : 0;
        grid[starti][startj] = -1;
        int num = 0;
        for (int i = 0; i < 4; i++)
            num += dfs(grid, starti + direction[i][0], startj + direction[i][1], remain - 1);
        grid[starti][startj] = 0;
        return num;
    }
};