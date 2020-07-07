#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> indexs(matrix.size(), 0);
        int currentNum = 0;
        int currentMin = 0, minIndex = 0;
        int len1 = matrix.size(), len2 = matrix[0].size();
        int i;
        for (currentNum = 0; currentNum < k; currentNum++) {
            currentMin = matrix[len1 - 1][len2 - 1] + 1;
            for (i = 0; i < len1 ; i++) {
                if (indexs[i] >= len2)
                    continue;
                if (i == 0) {
                    currentMin = matrix[0][indexs[0]];
                    minIndex = 0;
                }
                else if (indexs[i] < indexs[i - 1]) {
                    if (currentMin > matrix[i][indexs[i]]) {
                        currentMin = matrix[i][indexs[i]];
                        minIndex = i;
                    }
                }
            }
            indexs[minIndex]++;
        }
        return currentMin;
    }
};