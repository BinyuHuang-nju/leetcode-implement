#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        vector<vector<double>> dp(A.size(), vector<double>(K + 1, 0));
        vector<int> sum(A.size(), 0);
        sum[0] = A[0];
        dp[0][1] = (double)A[0];
        for (int i = 1; i < A.size(); i++) {
            sum[i] = sum[i - 1] + A[i];
            dp[i][1] = (double)sum[i] / (i + 1);
        }
        for (int i = 1; i < A.size(); i++) {
            for (int k = 2; k <= K && k <= i + 1; k++) { //k <= i+1
                for (int j = 0; j < i; j++) {
                    dp[i][k] = max(dp[i][k], dp[j][k - 1] + ((double)sum[i] - sum[j]) / (i - j));
                }
            }
        }
        return dp[A.size() - 1][K];
    }
private:
    double max(double x, double y) {
        return x > y ? x : y;
    }
};
int main() {
    vector<int> a = { 1,2,3,4,5,6,7 };
    Solution sol;
    double result=sol.largestSumOfAverages(a, 4);
    return 0;
}