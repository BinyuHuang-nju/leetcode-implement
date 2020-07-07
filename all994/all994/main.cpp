#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class Solution {
private:
    int dir[4][2] = { {-1,0},{0,-1},{0,1},{1,0} };
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> que;
        int i, j, len1 = grid.size(), len2 = grid[0].size();
        bool exist_1 = false;
        for(i=0;i<len1;i++)
            for (j = 0; j < len2; j++) {
                if (grid[i][j] == 2)
                    que.push({ i,j });
                else if (grid[i][j] == 1 && !exist_1)
                    exist_1 = true;
            }
        if (!exist_1)
            return 0;
        if (que.empty())
            return -1;
        que.push({ -1,-1 });
        int x, y, x_cur, y_cur;
        int time = 0;
        while (!que.empty()) {
            x = que.front()[0];
            y = que.front()[1];
            que.pop();
            //grid[x][y] = 2;
            for (i = 0; i < 4; i++) {
                x_cur = x + dir[i][0];
                y_cur = y + dir[i][1];
                if (x_cur < 0 || y_cur < 0 || x_cur >= len1 || y_cur >= len2)
                    continue;
                if (grid[x_cur][y_cur] == 1) {
                    grid[x_cur][y_cur] = 2;
                    que.push({ x_cur,y_cur });
                }
            }
            if (!que.empty() && que.front()[0] == -1) {
                que.pop();
                if (!que.empty()) {
                    que.push({ -1,-1 });
                    time++;
                }
            }
        }
        for (i = 0; i < len1; i++)
            for (j = 0; j < len2; j++)
                if (grid[i][j] == 1)
                    return -1;
        return time;
    }
};
int main() {
    vector<vector<int>> a = { {2,1,1},{1,1,0},{0,1,1} };
    Solution sol;
    cout << sol.orangesRotting(a);
    return 0;
}