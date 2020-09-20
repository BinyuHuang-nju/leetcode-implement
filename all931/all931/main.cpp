#include <iostream>
using namespace std;
#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int size = A.size();
        if (size == 0)
            return 0;
        if (size == 1)
            return A[0][0];
        vector<vector<int>> curmin(size, vector<int>(size, 0));
        for (int i = 0; i < size; i++)
            curmin[0][i] = A[0][i];
        int minval = INT_MAX;
        for (int i = 1; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (j == 0) {
                    curmin[i][0] = min(curmin[i - 1][0], curmin[i - 1][1]) + A[i][0];
                }
                else if (j == size - 1) {
                    curmin[i][size - 1] = min(curmin[i - 1][size - 2], curmin[i - 1][size - 1]) + A[i][size - 1];
                }
                else {
                    curmin[i][j] = min(min(curmin[i - 1][j - 1], curmin[i - 1][j]), curmin[i - 1][j + 1]) + A[i][j];
                }
                if (i == size - 1)
                    minval = min(minval, curmin[i][j]);
            }
        }
        return minval;
    }
};