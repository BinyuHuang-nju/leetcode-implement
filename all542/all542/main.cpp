#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class Solution {
private:
    int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return matrix;
        queue<vector<int>> nodes;
        int i, j, len1 = matrix.size(), len2 = matrix[0].size();
        for(i=0;i<len1;i++)
            for (j = 0; j < len2; j++) {
                if (matrix[i][j] == 0)
                    nodes.push({ i,j });
                else
                    matrix[i][j] = len1 + len2;
            }
        int x, y, x_cur, y_cur;
        vector<int> temp;
        while (!nodes.empty()) {
            temp = nodes.front();
            nodes.pop();
            x = temp[0];
            y = temp[1];
            for (i = 0; i < 4; i++) {
                x_cur = x + dir[i][0];
                y_cur = y + dir[i][1];
                if (x_cur < 0 || y_cur < 0 || x_cur >= len1 || y_cur >= len2)
                    continue;
                if (matrix[x_cur][y_cur] > matrix[x][y] + 1) {
                    matrix[x_cur][y_cur] = matrix[x][y] + 1;
                    nodes.push({ x_cur,y_cur });
                }
            }
        }
        return matrix;
    }
};