#include <iostream>
using namespace std;
#include <vector>

class Solution {
private:
    
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<vector<int>> graphs(edges.size() + 1);
        int v = 0, w = 0;
        for (vector<int> edge : edges) {
            v = edge[0];
            w = edge[1];
            if (existspath(w, v, graphs))
                return edge;
        }
    }
    bool existspath(int u, int v, vector<vector<int>>& graphs) {

    }
};