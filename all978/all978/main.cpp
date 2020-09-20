#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        if (A.size() < 2)
            return A.size();
        vector<int> dp(A.size(), 1);
        dp[1] = (A[0] == A[1]) ? 1 : 2;
        int maxLen = dp[1];
        for (int i = 2; i < A.size(); i++) {
            if ((A[i - 2] > A[i - 1] && A[i - 1] < A[i]) || (A[i - 2] < A[i - 1] && A[i - 1] > A[i])) {
                dp[i] = dp[i - 1] + 1;
            }
            else {
                dp[i] = (A[i - 1] == A[i]) ? 1 : 2;
            }
            if (dp[i] > maxLen)
                maxLen = dp[i];
        }
        return maxLen;
    }
};