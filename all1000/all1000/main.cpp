#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int N = stones.size();
        if (N < 2)
            return 0;
        if (N < K || K < 2)
            return -1;
        int rounds = (N - 1) / (K - 1);
        if (rounds * (K - 1) != (N - 1))
            return -1;
 
        vector<int> partsum(N + 1, 0);
        vector<vector<int>> cost(N, vector<int>(N, 0));
        for (int i = 1; i <= N; i++) {
            partsum[i] = partsum[i - 1] + stones[i - 1];
            cost[i - 1][i - 1] = stones[i - 1];
        }
        int low, high;
        for (low = N - K; low >= 0; low--) {
            for (high = low+1; high < N; high++) {

                cost[low][high] = cost[low][low] + cost[low + 1][high];
                for (int mid = low + (K - 1); mid + (K - 1) <= high; mid += (K - 1)) {
                    cost[low][high] = min(cost[low][high], cost[low][mid] + cost[mid + 1][high]);
                }
                if ((high - low) % (K - 1) == 0)
                    cost[low][high] += partsum[high + 1] - partsum[low];

            }
        }
        return cost[0][N - 1] - partsum[N];
    }
};