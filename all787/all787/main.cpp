#include <iostream>
using namespace std;
#include <vector>
#include <cmath>

class Solution1 {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> dp(n, vector<int>(K + 2, INT_MAX));
        for (int i = 0; i < K + 2; i++)
            dp[src][i] = 0;
        for (int i = 1; i < K + 2; i++) {
            for (vector<int> flight : flights) {
                if (dp[flight[0]][i - 1] != INT_MAX) {
                    dp[flight[1]][i] = min(dp[flight[1]][i], dp[flight[0]][i - 1] + flight[2]);
                }
            }
        }
        return dp[dst][K + 1] == INT_MAX ? -1 : dp[dst][K + 1];
    }
private:
    int min(int x, int y) {
        return x < y ? x : y;
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> graph(n, vector<int>(n, -1));
        for (vector<int> flight : flights) {
            graph[flight[0]][flight[1]] = flight[2];
        }
        vector<int> visited(n, false);
        visited[src] = true;
        int minCost = INT_MAX;
        dfs(n, graph, src, dst, src, K, 0, minCost, 0, visited);
        return minCost == INT_MAX ? -1 : minCost;
    }
private:
    void dfs(int n, vector<vector<int>>& graph, int src, int dst, int curSrc, int K, int curK, \
        int& minCost, int curCost, vector<int>& visited) {
        if (curSrc == dst) {
            minCost = min(minCost, curCost);
            return;
        }
        if (curK > K || curCost > minCost)
            return;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && graph[curSrc][i] != -1) {
                visited[i] = true;
                dfs(n, graph, src, dst, i, K, curK + 1, minCost, curCost + graph[curSrc][i], visited);
                visited[i] = false;
            }
        }
    }

    int min(int x, int y) {
        return x < y ? x : y;
    }
};
