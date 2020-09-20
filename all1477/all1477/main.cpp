#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <algorithm>
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        map<int, int> pre_mp;
        pre_mp[0] = -1;
        vector<int> shortest_array(n, INT_MAX);
        int sum = 0;
        int result = INT_MAX;
        for (int i = 0; i < n; i++) {
            sum = sum + arr[i];
            if (!pre_mp.count(sum-target)) {
                pre_mp[sum] = i;
                shortest_array[i] = (i > 0) ? shortest_array[i - 1] : INT_MAX;
                continue;
            }
            int l = pre_mp[sum - target];
            int len1 = i - l, len2 = (l == -1) ? INT_MAX : shortest_array[l];
            pre_mp[sum] = i;
            shortest_array[i] = (i > 0) ? min(shortest_array[i - 1], len1) : len1;
            if (len2 == INT_MAX)
                continue;
            result = min(result, len1 + len2);
        }
        return (result == INT_MAX) ? -1 : result;
    }
};
int main() {
    Solution sol;
    vector<int> a = { 3,2,2,4,3 };
    sol.minSumOfLengths(a, 3);
    return 0;
}