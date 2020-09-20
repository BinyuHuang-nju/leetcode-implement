#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        long long M = 1e9 + 7;
        vector<int> presum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            presum[i] = presum[i - 1] + nums[i - 1];
        }
        vector<int> results;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                results.push_back(presum[j] - presum[i - 1]);
            }
        }
        sort(results.begin(), results.end());
        long long answer = 0;
        for (int i = left - 1; i < right; i++)
            answer = (answer + results[i]) % M;
        return (int)answer;
    }
};
int main() {
    Solution sol;
    vector<int> a = { 1,2,3,4 };
    sol.rangeSum(a, 4, 1, 5);
    return 0;
}