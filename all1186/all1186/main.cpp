#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        vector<vector<int>> dp(arr.size(), vector<int>(2, 0));
        int result = arr[0];
        dp[0][0] = arr[0];
        dp[0][1] = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
            result = max(result, max(dp[i][0], dp[i][1]));
        }
        return result;
    }
};
int main() {
    vector<int> a = { 1,-2,0,3 };
    Solution sol;
    sol.maximumSum(a);
    return 0;
}