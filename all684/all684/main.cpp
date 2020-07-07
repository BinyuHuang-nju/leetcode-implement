#include <iostream>
using namespace std;
#include <vector>

class UFSet {
private:
    int* parent;
    int size;
public:
    UFSet(int num) {
        size = num + 1;
        parent = new int[num + 1];
        for (int i = 0; i <= num; i++)
            parent[i] = -1;
    }
    int find(int x) {
        while (parent[x] >= 0)
            x = parent[x];
        return x;
    }
    void unions(int x, int y) {
        int temp = parent[x] + parent[y];
        if (parent[x] > parent[y]) {
            parent[x] = y;
            parent[y] = temp;
        }
        else {
            parent[y] = x;
            parent[x] = temp;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UFSet ufs(edges.size());
        int v = 0, w = 0;
        for (vector<int> edge : edges) {
            v = edge[0];
            w = edge[1];
            int m = ufs.find(v), n = ufs.find(w);
            if (m == n)
                return edge;
            ufs.unions(m, n);
        }
        return { v,w };
    }
};
int main() {
    Solution sol;
    vector<vector<int>> edges = { {1,2},{2,3},{3,4},{1,4},{1,5} };
    vector<int> result = sol.findRedundantConnection(edges);
    return 0;
}