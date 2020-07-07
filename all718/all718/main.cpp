#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int len1 = A.size(), len2 = B.size();
        vector<vector<int>> length(len1 + 1, vector<int>(len2 + 1, 0));
        int maxlength = 0;
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (A[i - 1] == B[j - 1]) {
                    length[i][j] = length[i - 1][j - 1] + 1;
                    if (length[i][j] > maxlength)
                        maxlength = length[i][j];
                }
            }
        }
        return maxlength;
    }
};