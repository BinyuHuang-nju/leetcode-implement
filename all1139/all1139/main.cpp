#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int len1 = grid.size(), len2 = grid[0].size();
        vector<vector<vector<int>>> seq(len1 + 1, vector<vector<int>>(len2 + 1, vector<int>(2, 0)));
        int result = 0;
        //vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (grid[i - 1][j - 1] == 1) {
                    seq[i][j][0] = seq[i - 1][j][0] + 1;
                    seq[i][j][1] = seq[i][j - 1][1] + 1;
                    int s = min(seq[i][j][0], seq[i][j][1]);
                    for (int k = s - 1; k >= 0; k--) {
                        if (seq[i - k][j][1] > k&& seq[i][j - k][0] > k) {
                            result = max(result, k + 1);
                            break;
                        }
                    }
                }
            }
        }
        return result * result;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> a = { {1,1,0,0} };
    sol.largest1BorderedSquare(a);
    return 0;
}