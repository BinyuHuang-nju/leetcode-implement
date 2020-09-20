#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size(), choose = n / 3;
        vector<vector<int>> dp1(n+1, vector<int>(choose + 1, 0));
        vector<vector<int>> dp2(n+1, vector<int>(choose + 1, 0));
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= choose; j++) {
                dp1[i][j] = max(dp1[i - 1][j], i - 2 >= 0 ? (dp1[i - 2][j - 1] + slices[i - 1]) : slices[i - 1]);
            }
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= choose; j++) {
                dp2[i][j] = max(dp2[i - 1][j], i - 2 >= 1 ? (dp2[i - 2][j - 1] + slices[i - 1]) : slices[i - 1]);
            }
        }
        return max(dp1[n - 1][choose], dp2[n][choose]);
    }
};
int main() {
    Solution sol;
    vector<int> a = { 1,2,3,4,5,6 };
    sol.maxSizeSlices(a);
    return 0;
}