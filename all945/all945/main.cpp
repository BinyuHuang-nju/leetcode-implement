#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if (A.size() < 2)
            return 0;
        int res = 0;
        sort(A.begin(), A.end());
        for (int i = 1; i < A.size(); i++) {
            if (A[i - 1] >= A[i]) {
                res += A[i - 1] + 1 - A[i];
                A[i] = A[i - 1] + 1;
            }
        }
        return res;
    }
};