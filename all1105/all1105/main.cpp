#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n = books.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int tmp_w = 0, tmp_h = 0, j = i;
            for (; j > 0; j--) {
                tmp_w += books[j - 1][0];
                if (tmp_w > shelf_width)
                    break;
                tmp_h = max(tmp_h, books[j - 1][1]);
                dp[i] = min(dp[i], dp[j - 1] + tmp_h);
            }
        }
        return dp[n];
    }
};