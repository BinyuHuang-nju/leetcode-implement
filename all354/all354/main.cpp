#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
private:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] < b[0])
            return true;
        else if (a[0] > b[0])
            return false;
        return (a[1] <= b[1]);
    }
    int max(int a, int b) {
        return a > b ? a : b;
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.size() < 2)
            return envelopes.size();
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> dp(envelopes.size(), 1);
        int i, j;
        int maxres = 1;
        for (i = 1; i < envelopes.size(); i++) {
            for (j = 0; j < i; j++) {
                if (envelopes[j][0] == envelopes[i][0])
                    break;
                if (envelopes[j][1] < envelopes[i][1])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            maxres = max(maxres, dp[i]);
        }
        return maxres;
    }
};