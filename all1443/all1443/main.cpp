#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution1 {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> neighbors(n);
        vector<bool> visited(n, false);
        for (vector<int> edge : edges) {
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]);
        }
        int result = 0;
        dfs(result, 0, neighbors, visited, hasApple);
        return result;
    }
    int dfs(int& result, int v, vector<vector<int>>& neighbors, vector<bool>& visited, vector<bool>& hasApple) {
        visited[v] = true;
        bool hasApp = hasApple[v];
        for (int w : neighbors[v]) {
            if (visited[w])
                continue;
            int num = dfs(result, w, neighbors, visited, hasApple);
            if (num >= 0) {
                hasApp = true;
                result = result + 2;
            }
        }
        return hasApp ? 1 : -1;
    }
};
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> neighbors(n);
        vector<bool> visited(n, false);
        for (vector<int> edge : edges) {
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]);
        }
        int ret = dfs( 0, neighbors, visited, hasApple);
        return ret > 0 ? ret : 0;
    }
    int dfs(int v, vector<vector<int>>& neighbors, vector<bool>& visited, vector<bool>& hasApple) {
        visited[v] = true;
        bool hasApp = hasApple[v];
        int ret = 0;
        for (int w : neighbors[v]) {
            if (visited[w])
                continue;
            int num = dfs(w, neighbors, visited, hasApple);
            if (num >= 0) {
                hasApp = true;
                ret += num + 2;
            }
        }
        return hasApp ? ret : -1;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> edges = { {0,1},{0,2},{1,4},{1,5},{2,3},{2,6} };
    vector<bool> hasApple = { false,false,true,false,true,true,false };
    sol.minTime(7, edges, hasApple);
    return 0;
}