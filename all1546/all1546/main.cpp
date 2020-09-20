#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <map>
class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> presum(n + 1, 0);
        map<int, int> lastsub;
        lastsub[0] = 0;
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            presum[i] = presum[i - 1] + nums[i - 1];
            int aim = presum[i] - target;
            dp[i] = dp[i - 1];
            if (lastsub.count(aim)) {
                int j = lastsub[aim];
                dp[i] = max(dp[i], dp[j] + 1);
            }
            lastsub[presum[i]] = i;
        }
        return dp[n];
    }
};
int main() {
    Solution sol;
    vector<int> a = { 0,0,0 };
    sol.maxNonOverlapping(a, 0);
    return 0;
}