#include <iostream>
using namespace std;
#include <vector>
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int len1 = matrix.size(), len2 = matrix[0].size();
        vector<vector<int>> subsum(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 1; i <= len1; i++) {
            int cursum = 0;
            for (int j = 1; j <= len2; j++) {
                cursum += matrix[i - 1][j - 1];
                subsum[i][j] = subsum[i - 1][j] + cursum;
            }
        }
        int result = 0;
        for (int i1 = 1; i1 <= len1; i1++) {
            for (int j1 = 1; j1 <= len2; j1++) {
                for (int i2 = i1; i2 <= len1; i2++) {
                    for (int j2 = j1; j2 <= len2; j2++) {
                        if (subsum[i2][j2] + subsum[i1 - 1][j1 - 1] - subsum[i2][j1 - 1] - subsum[i1 - 1][j2] == target)
                            result++;
                    }
                }
            }
        }
        return result;
    }
};