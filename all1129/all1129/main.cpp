#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
class Solution {
private:
    struct Node {
        bool red_visited;
        bool blue_visited;
        vector<int> red_neighbors;
        vector<int> blue_neighbors;
        int red_path;
        int blue_path;
        Node() :red_visited(false), blue_visited(false), red_path(INT_MAX), blue_path(INT_MAX) {}
    };
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        Node* graph = new Node[n]();
        for (vector<int> red_edge : red_edges) {
            graph[red_edge[0]].red_neighbors.push_back(red_edge[1]);
        }
        for (vector<int> blue_edge : blue_edges) {
            graph[blue_edge[0]].blue_neighbors.push_back(blue_edge[1]);
        }
        queue<pair<int, int>> queNode;
        graph[0].red_visited = graph[0].blue_visited = true;
        graph[0].red_path = graph[0].blue_path = 0;
        queNode.push(make_pair(0, -1));
        int v, w, state;
        while (!queNode.empty()) {
            v = queNode.front().first;
            state = queNode.front().second;
            queNode.pop();
            if (state != 0) {  // last edge is blue
                for (int i = 0; i < graph[v].red_neighbors.size(); i++) {
                    w = graph[v].red_neighbors[i];
                    if (!graph[w].red_visited) {
                        graph[w].red_visited = true;
                        graph[w].red_path = graph[v].blue_path + 1;
                        queNode.push(make_pair(w, 0));
                    }
                }
            }
            if (state != 1) {  //last edge is red
                for (int i = 0; i < graph[v].blue_neighbors.size(); i++) {
                    w = graph[v].blue_neighbors[i];
                    if (!graph[w].blue_visited) {
                        graph[w].blue_visited = true;
                        graph[w].blue_path = graph[v].red_path + 1;
                        queNode.push(make_pair(w, 1));
                    }
                }
            }
        }
        vector<int> results;
        results.push_back(0);
        for (int i = 1; i < n; i++) {
            if (graph[i].red_path == INT_MAX && graph[i].blue_path == INT_MAX)
                results.push_back(-1);
            else
                results.push_back(min(graph[i].red_path, graph[i].blue_path));
        }
        delete[]graph;
        return results;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> red = { {0,1} }, blue = { {1,2} };
    sol.shortestAlternatingPaths(3, red, blue);
    return 0;
}