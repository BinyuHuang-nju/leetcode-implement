#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution1 {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        int states = 1 << n;
        vector<int> pre_course(n, 0);
        for (vector<int> dependency : dependencies) {
            int xi = dependency[0] - 1, yi = dependency[1] - 1;
            pre_course[yi] = pre_course[yi] | (1 << xi);
        }
        vector<int> state_count(states, 0);
        for (int i = 0; i < states; i++) {
            for (int j = 0; j < n; j++)
                if ((i >> j) & 1)
                    state_count[i]++;
        }
        vector<int> dp(states, INT_MAX / 2);
        dp[0] = 0;
        for (int state = 0; state < states; state++) {
            int can_study = 0;
            for (int i = 0; i < n; i++) {
                if (((state >> i) & 1) == 0 && (pre_course[i] & state) == pre_course[i])
                    can_study = can_study | (1 << i);
            }
            if (state_count[can_study] <= k)
                dp[state | can_study] = min(dp[state | can_study], dp[state] + 1);
            else {
                for (int j = can_study; j > 0; j = (j - 1) & can_study) {
                    if (state_count[j] == k)
                        dp[state | j] = min(dp[state | j], dp[state] + 1);
                }
            }
        }
        return dp[states - 1];
    }
};

class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        int states = 1 << n;
        vector<int> pre_course(n, 0);
        for (vector<int> dependency : dependencies) {
            int xi = dependency[0] - 1, yi = dependency[1] - 1;
            pre_course[yi] = pre_course[yi] | (1 << xi);
        }
        vector<int> state_count(states, 0);
        state_count[1] = 1;
        int pre = 1, cur = 1, next = 2;
        for (int i = 1; i < n; i++) {
            cur = next;
            next = 2 * next;
            int rec = cur + pre;
            for (int i = 0; i < cur - pre; i++)
                state_count[cur + i] = state_count[pre + i];
            for (int i = 0; i < pre; i++)
                state_count[rec + i] = state_count[cur + i] + 1;
            pre = cur;
        }
        vector<int> dp(states, INT_MAX / 2);
        dp[0] = 0;
        for (int state = 0; state < states; state++) {
            int can_study = 0;
            for (int i = 0; i < n; i++) {
                if (((state >> i) & 1) == 0 && (pre_course[i] & state) == pre_course[i])
                    can_study = can_study | (1 << i);
            }
            if (state_count[can_study] <= k)
                dp[state | can_study] = min(dp[state | can_study], dp[state] + 1);
            else {
                for (int j = can_study; j > 0; j = (j - 1) & can_study) {
                    if (state_count[j] == k)
                        dp[state | j] = min(dp[state | j], dp[state] + 1);
                }
            }
        }
        return dp[states - 1];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> a = { {2,1},{3,1},{4,1},{1,5} };
    sol.minNumberOfSemesters(5, a, 2);
    return 0;
}