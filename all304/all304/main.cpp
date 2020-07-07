#include <iostream>
using namespace std;
#include <vector>

class NumMatrix {
private:
    vector<vector<int>> sums;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int sum = 0, i, j;
        vector<int> cur;
        for (i = 0; i < matrix.size(); i++) {
            sum = 0;
            cur.clear();
            if (i == 0) {
                for (j = 0; j < matrix[0].size(); j++) {
                    sum = sum + matrix[i][j];
                    cur.push_back(sum);
                }
            }
            else {
                for (j = 0; j < matrix[0].size(); j++) {
                    sum = sum + matrix[i][j];
                    cur.push_back(sums[i - 1][j] + sum);
                }
            }
            sums.push_back(cur);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = sums[row2][col2];
        if (row1)
            res = res - sums[row1 - 1][col2];
        if (col1)
            res = res - sums[row2][col1 - 1];
        if (row1 && col1)
            res = res + sums[row1 - 1][col1 - 1];
        return res;
    }
};