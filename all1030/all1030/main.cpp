#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        int direction[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        vector<vector<int>> results;
        queue<vector<int>> que;
        que.push({ r0,c0 });
        visited[r0][c0] = true;
        vector<int> p;
        int r, c;
        while (!que.empty()) {
            p = que.front();
            que.pop();
            results.push_back(p);
            for (int i = 0; i < 4; i++) {
                r = p[0] + direction[i][0];
                c = p[1] + direction[i][1];
                if (r >= 0 && r < R && c >= 0 && c < C && !visited[r][c]) {
                    que.push({ r ,c });
                    visited[r][c] = true;
                }
            }
        }
        return results;
    }
};