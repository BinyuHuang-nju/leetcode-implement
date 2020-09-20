#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <algorithm>

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int len = A.size();
        if (len < 3)
            return len;
        int result = 2;
        vector<map<int, int>> list(len);
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < i; j++) {
                if (!list[j].count(A[i] - A[j]))
                    list[i][A[i] - A[j]] = 2;
                else {
                    list[i][A[i] - A[j]] = list[j][A[i] - A[j]] + 1;
                    result = max(result, list[i][A[i] - A[j]]);
                }
            }
        }
        return result;
    }
};