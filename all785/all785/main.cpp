#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        if (graph.size() <= 2)
            return true;
        vector<bool> visited(graph.size(), false);
        vector<bool> color(graph.size(), false);
        queue<int> que;
        //que.push(0);
        int i, v, w;
        for (int a = 0; a < graph.size(); a++) {
            if (!visited[a])
                que.push(a);
            while (!que.empty()) {
                v = que.front();
                que.pop();
                visited[v] = true;
                for (i = 0; i < graph[v].size(); i++) {
                    w = graph[v][i];
                    if (!visited[w]) {
                        color[w] = !color[v];
                        que.push(w);
                    }
                    else {
                        if (color[v] == color[w])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};
int main() {
    vector<vector<int>> a = { {1,3},{0,2},{1,3},{0,2} };
    Solution sol;
    cout << sol.isBipartite(a);
    return 0;
}