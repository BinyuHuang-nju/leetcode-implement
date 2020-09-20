#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long int pre = arr[0], mid = arr[0], post = arr[arr.size() - 1], sum = 0;
        long long int tmp_pre = 0, tmp_post = 0, tmp_mid = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            tmp_pre += arr[i];
            if (tmp_pre > pre)
                pre = tmp_pre;
            tmp_mid = max(tmp_mid + arr[i], (long long)arr[i]);
            mid = max(mid, tmp_mid);
        }
        for (int i = arr.size() - 1; i >= 0; i--) {
            tmp_post += arr[i];
            if (tmp_post > post)
                post = tmp_post;
        }
        if (mid < 0)
            return 0;
        if (k == 1)
            return mid % 1000000007;
        if (sum < 0)
            return max(mid, post + pre) % 1000000007;
        return max(mid, max(post, sum) + sum * (k - 2) + max(pre, sum)) % 1000000007;
    }
};
int main() {
    Solution sol;
    vector<int> a = { 1,-1 };
    sol.kConcatenationMaxSum(a, 1);
    return 0;
}