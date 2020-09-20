#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <algorithm>
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int len = grid.size();
        int direction[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
        queue<vector<int>> queNode;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                if (grid[i][j] == 1) {
                    queNode.push({ i,j });
                }
            }
        }
        if (queNode.empty() || queNode.size() == len * len)
            return -1;
        int lastx = 0, lasty = 0;
        while (!queNode.empty()) {
            lastx = queNode.front()[0];
            lasty = queNode.front()[1];
            queNode.pop();
            for (int i = 0; i < 4; i++) {
                int newx = lastx + direction[i][0], newy = lasty + direction[i][1];
                if (newx < 0 || newx >= len || newy < 0 || newy >= len || grid[newx][newy] != 0)
                    continue;
                grid[newx][newy] = grid[lastx][lasty] + 1;
                queNode.push({ newx,newy });
            }
        }
        return grid[lastx][lasty] - 1;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> a = { {1,0,0,0,0},{0,0,0,0,1},{0,0,0,0,0},{0,0,0,0,0} ,{1,0,0,0,0} };
    sol.maxDistance(a);
    return 0;
}