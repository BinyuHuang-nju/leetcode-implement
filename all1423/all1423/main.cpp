#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution1 {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> preffix(n + 1, 0);
        for (int i = 1; i <= n; i++)
            preffix[i] = preffix[i - 1] + cardPoints[i - 1];
        int result = preffix[k];
        for (int i = k - 1; i >= 0; i--) {
            result = max(result, preffix[i] + preffix[n] - preffix[n - k + i]);
        }
        return result;
    }
};
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int mx = 0;
        for (int i = 0; i < k; i++)
            mx += cardPoints[i];
        int result = mx;
        for (int i = k - 1, j = n - 1; i>=0; i--,j--) {
            mx = mx - cardPoints[i] + cardPoints[j];
            result = max(result, mx);
        }
        return result;
    }
};
int main() {
    vector<int> a = { 1,2,3,4,5,6,1 };
    Solution sol;
    sol.maxScore(a, 3);
}