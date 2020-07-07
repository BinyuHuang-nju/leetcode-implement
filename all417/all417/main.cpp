#include <iostream>
using namespace std;
#include <vector>
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return res;
        int len1 = matrix.size(), len2 = matrix[0].size();
        vector<vector<bool>> pacific(len1, vector<bool>(len2, false));
        vector<vector<bool>> atlantic(len1, vector<bool>(len2, false));
        int i, j;
        for (i = 0; i < len1; i++) {
            dfs(matrix, pacific, i, 0, 0);
            dfs(matrix, atlantic, i, len2 - 1, 0);
        }
        for (j = 0; j < len2; j++) {
            dfs(matrix, pacific, 0, j, 0);
            dfs(matrix, atlantic, len1 - 1, j, 0);
        }
        for (i = 0; i < len1; i++)
            for (j = 0; j < len2; j++)
                if (pacific[i][j] && atlantic[i][j])
                    res.push_back({ i,j });
        return res;
    }
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& effect, int x, int y, int pre) {
        if (x < 0 || y < 0 || x >= matrix.size() || y >= matrix[0].size())
            return;
        if (effect[x][y] || matrix[x][y] < pre)
            return;
        effect[x][y] = true;
        dfs(matrix, effect, x - 1, y, matrix[x][y]);
        dfs(matrix, effect, x + 1, y, matrix[x][y]);
        dfs(matrix, effect, x, y - 1, matrix[x][y]);
        dfs(matrix, effect, x, y + 1, matrix[x][y]);
    }
};