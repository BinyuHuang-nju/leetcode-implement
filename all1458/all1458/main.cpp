#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        //int result = INT_MIN;
        vector<vector<int>> dp(len1, vector<int>(len2, 0));
        dp[0][0] = nums1[0] * nums2[0];
        for (int i = 1; i < len1; i++) {
            dp[i][0] = max(dp[i - 1][0], nums1[i] * nums2[0]);
        }
        for (int j = 1; j < len2; j++) {
            dp[0][j] = max(dp[0][j - 1], nums1[0] * nums2[j]);
        }
        for (int i = 1; i < len1; i++) {
            for (int j = 1; j < len2; j++) {
                dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), (dp[i - 1][j - 1] > 0 ? dp[i - 1][j - 1] : 0) + (nums1[i] * nums2[j] > 0 ? nums1[i] * nums2[j] : 0));
            }
        }
        return dp[len1 - 1][len2 - 1];
    }
};
int main() {
    Solution sol;
    vector<int> a = { -3,-8,3,-10,1,3,9    }, b = { 9,2,3,7,-9,1,-8,5,-1,-1 };
    int x = sol.maxDotProduct(a, b);
    return 0;
}