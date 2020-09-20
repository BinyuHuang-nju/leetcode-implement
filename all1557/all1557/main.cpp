#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, true);
        for (vector<int> edge : edges) {
            visited[edge[1]] = false;
        }
        vector<int> results;
        for (int i = 0; i < n; i++) {
            if (visited[i])
                results.push_back(i);
        }
        return results;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> a = { {0,1},{0,2},{2,5},{3,4},{4,2} };
    sol.findSmallestSetOfVertices(6, a);
    return 0;
}