#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() < 2)
            return 0;
        else if (cost.size() == 2)
            return cost[0] > cost[1] ? cost[0] : cost[1];
        vector<int> mincosts(cost.size() + 1, 0);
        for (int i = 2; i <= cost.size(); i++) {
            mincosts[i] = min(mincosts[i - 2] + cost[i - 2], mincosts[i - 1] + cost[i - 1]);
        }
        return mincosts[cost.size()];
    }
private:
    int min(int x, int y) {
        return x < y ? x : y;
    }
};