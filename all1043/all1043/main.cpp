#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        vector<int> submax(A.size(), 0);
        for (int i = 0; i < A.size(); i++) {
            int domainMax = A[i];
            for (int j = 1; j <= K && j <= i + 1; j++) {
                domainMax = max(domainMax, A[i - j + 1]);
                submax[i] = max(submax[i], ((i < j) ? 0 : submax[i - j]) + domainMax * j);
            }
        }
        return submax[A.size() - 1];
    }
};