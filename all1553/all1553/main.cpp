#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution1 {
public:
    int minDays(int n) {
        vector<int> cost(n + 1, INT_MAX);
        cost[0] = 0;
        for (int i = 1; i <= n; i++) {
            cost[i] = cost[i - 1] + 1;
            if (i % 2 == 0)
                cost[i] = min(cost[i], cost[i / 2] + 1);
            if (i % 3 == 0)
                cost[i] = min(cost[i], cost[i / 3] + 1);
        }
        return cost[n];
    }
};
class Solution2 {
public:
    int minDays(int n) {
        vector<int> cost(n + 1, INT_MAX);
        cost[0] = 0;
        for (int i = 1; i <= n; i++) {
            
            cost[i] = 1 + min(cost[i / 2] + i % 2, cost[i / 3] + i % 3);
        }
        return cost[n];
    }
};
class Solution {
public:
    vector<int> cost;
    int minDays(int n) {
        cost = vector<int>(n + 1, INT_MAX);
        if (n < 2)
            return n;
        cost[0] = 0;
        cost[1] = 1;
        return dfs(n);
    }
    int dfs(int n) {
        if (cost[n] != INT_MAX)
            return cost[n];
        return cost[n] = 1 + min(dfs(n / 2) + n % 2, dfs(n / 3) + n % 3);
    }
};