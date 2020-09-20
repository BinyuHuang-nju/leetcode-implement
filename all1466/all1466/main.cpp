#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <queue>
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, bool>>> graph(n);
        for (vector<int> connection : connections) {
            graph[connection[0]].push_back(make_pair(connection[1], true));
            graph[connection[1]].push_back(make_pair(connection[0], false));
        }
        int result = 0;
        vector<bool> visited(n, false);
        queue<int> queNode;
        queNode.push(0);
        visited[0] = true;
        int v, w;
        while (!queNode.empty()) {
            v = queNode.front();
            queNode.pop();
            for (pair<int, bool> s : graph[v]) {
                w = s.first;
                if (visited[w])
                    continue;
                if (s.second)
                    result++;
                visited[w] = true;
                queNode.push(w);
            }
        }
        return result;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> a = { {0,1},{1,3},{2,3},{4,0},{4,5} };
    sol.minReorder(6, a);
    return 0;
}