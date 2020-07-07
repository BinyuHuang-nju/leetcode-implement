#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int i, j;
        vector<vector<int>> hp(dungeon.size(), vector<int>(dungeon[0].size(), 0));
        int row = dungeon.size(), col = dungeon[0].size();
        hp[row - 1][col - 1] = dungeon[row - 1][col - 1] < 0 ? 1 - dungeon[row - 1][col - 1] : 1;
        for (i = row - 2; i >= 0; i--)
            hp[i][col - 1] = max(1, hp[i + 1][col - 1] - dungeon[i][col - 1]);
        for (i = col - 2; i >= 0; i--)
            hp[row - 1][i] = max(1, hp[row - 1][i + 1] - dungeon[row - 1][i]);
        for (i = row - 2; i >= 0; i--) {
            for (j = col - 2; j >= 0; j--)
                hp[i][j] = max(1, min(hp[i + 1][j], hp[i][j + 1]) - dungeon[i][j]);
        }
        return hp[0][0];
    }
    int max(int x, int y) {
        return x > y ? x : y;
    }
    int min(int x, int y) {
        return x < y ? x : y;
    }
};