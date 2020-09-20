#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <queue>

class Solution {
private:
    struct Node {
        vector<int> neighbors;
        vector<int> weights;
    };
    struct NodeCondition {
        bool visited;
        int distance;
        NodeCondition() :visited(false), distance(INT_MAX) {}
    };
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        Node* graph = new Node[n];
        for (vector<int> edge : edges) {
            graph[edge[0]].neighbors.push_back(edge[1]);
            graph[edge[0]].weights.push_back(edge[2]);
            graph[edge[1]].neighbors.push_back(edge[0]);
            graph[edge[1]].weights.push_back(edge[2]);
        }
        int minNode = -1, minNeighbors = INT_MAX;
        for (int s = 0; s < n; s++) {
            int curNeighbors = 0;
            NodeCondition* nodes = new NodeCondition[n]();
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queNode;
            nodes[s].visited = true;
            nodes[s].distance = 0;
            queNode.push(make_pair(0, s));
            int v, w, dis, newPriority;
            while (!queNode.empty()) {
                v = queNode.top().second;
                dis = queNode.top().first;
                queNode.pop();
                if (dis > nodes[v].distance)  // This step is to correct the problem
                    continue;                        // of push!=decreaseKey
                for (int i = 0; i < graph[v].neighbors.size(); i++) {
                    w = graph[v].neighbors[i];
                    newPriority = dis + graph[v].weights[i];
                    if (newPriority > distanceThreshold)
                        continue;
                    if (!nodes[w].visited) {
                        nodes[w].visited = true;
                        nodes[w].distance = newPriority;
                        queNode.push(make_pair(newPriority, w));
                    }
                    else {
                        if (newPriority < nodes[w].distance) {
                            nodes[w].distance = newPriority;
                            queNode.push(make_pair(newPriority, w));
                        }
                    }
                }
            }
            for (int i = 0; i < n; i++)
                if (i != s && nodes[i].visited)
                    curNeighbors++;
            delete[]nodes;
            if (curNeighbors <= minNeighbors) {
                minNeighbors = curNeighbors;
                minNode = s;
            }
        }
        delete[]graph;
        return minNode;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> edges = { {0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1} };
    sol.findTheCity(5, edges, 2);
    return 0;
}