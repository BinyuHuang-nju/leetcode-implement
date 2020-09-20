#include <iostream>
using namespace std;
#include <vector>

class Solution {
private:
    struct Node {
        bool visited;
        int color;
        vector<int> neighbors;
        Node() :visited(false) {}
    };
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        Node* graph = new Node[N+1]();
        vector<int> results;
        for (vector<int> path : paths) {
            graph[path[0]].neighbors.push_back(path[1]);
            graph[path[1]].neighbors.push_back(path[0]);
        }
        int  w;
        for (int i = 1; i <= N; i++) {
            bool remainingcolor[4] = { true,true,true,true };
            for (int j = 0; j < graph[i].neighbors.size(); j++) {
                w = graph[i].neighbors[j];
                if (graph[w].visited)
                    remainingcolor[graph[w].color-1] = false;
            }
            for(int j=0;j<4;j++)
                if (remainingcolor[j]) {
                    graph[i].color = j + 1;
                    break;
                }
            graph[i].visited = true;
            results.push_back(graph[i].color);
        }
        delete[]graph;
        return results;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> a = { {1,2},{2,3}, {3,1} };
    vector<int> re = sol.gardenNoAdj(3, a);
    return 0;
};
