#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <map>

class Solution1 {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        int result = 0, sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (sum + satisfaction[i] > 0) {
                sum = sum + satisfaction[i];
                result = result + sum;
            }
            else
                break;
        }
        return result;
    }
};
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        int result = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                if (i == j)
                    dp[i][j] = dp[i - 1][j - 1] + j * satisfaction[i - 1];
                else
                    dp[i][j] = max(dp[i - 1][j - 1] + j * satisfaction[i-1], dp[i - 1][j]);
                result = max(dp[i][j], result);
            }
        }
        return result;
    }
};
int main() {
    Solution sol;
    vector<int> a = { -1,-8,0,5,-9 };
    sol.maxSatisfaction(a);
    return 0;
}