#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        const long long M = 1e9 + 7;
        int rows = pizza.size(), cols = pizza.front().length();
        vector<vector<int>> count(rows+1, vector<int>(cols+1, 0));
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                count[i][j] = count[i + 1][j] + count[i][j + 1] - count[i + 1][j + 1] + (pizza[i][j] == 'A' ? 1 : 0);
            }
        }
        vector<vector<vector<long long>>> memo(rows, vector<vector<long long>>(cols, vector<long long>(k + 1, 0)));
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                memo[i][j][1] = count[i][j] > 0 ? 1 : 0;
                for (int h = 2; h <= k; h++) {
                    for (int ii = i + 1; ii < rows; ii++) {
                        if (count[i][j] > count[ii][j])
                            memo[i][j][h] = (memo[i][j][h] + memo[ii][j][h - 1]) % M;
                    }
                    for (int jj = j + 1; jj < cols; jj++) {
                        if (count[i][j] > count[i][jj])
                            memo[i][j][h] = (memo[i][j][h] + memo[i][jj][h - 1]) % M;
                    }
                }
            }
        }
        return memo[0][0][k];
    }
};
int main() {
    vector<string> pizza = { "A..","AAA","..." };
    Solution sol;
    sol.ways(pizza, 3);
    return 0;
}