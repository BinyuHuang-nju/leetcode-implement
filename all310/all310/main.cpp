#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class Solution {
private:
    struct Node {
        bool visited;
        int dis;
        vector<int> neighbors;
        Node() { visited = false; dis = 0; }
    };
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return { 0 };
        if (n == 2)
            return { 0,1 };
        Node* nodes=new Node[n]();
        int i;
        for (i = 0; i < edges.size(); i++) {
            nodes[edges[i][0]].neighbors.push_back(edges[i][1]);
            nodes[edges[i][1]].neighbors.push_back(edges[i][0]);
        }
        queue<int> queNode;
        queNode.push(0);
        int v = 0, w;
        while (!queNode.empty()) {
            v = queNode.front();
            queNode.pop();
            nodes[v].visited = true;
            for (i = 0; i < nodes[v].neighbors.size(); i++) {
                w = nodes[v].neighbors[i];
                if (!nodes[w].visited)
                    queNode.push(w);
            }
        }
        int start = v;
        for (i = 0; i < n; i++)
            nodes[i].visited = false;
        nodes[start].dis = 0;
        queNode.push(start);
        while (!queNode.empty()) {
            v = queNode.front();
            queNode.pop();
            nodes[v].visited = true;
            for (i = 0; i < nodes[v].neighbors.size(); i++) {
                w = nodes[v].neighbors[i];
                if (!nodes[w].visited) {
                    nodes[w].dis = nodes[v].dis + 1;
                    queNode.push(w);
                }
            }
        }
        int end = v;
        vector<int> list;
        for (i = 0; i < n; i++)
            nodes[i].visited = false;
        createList(list, nodes, n, start, end);
        vector<int> res;
        /*if (nodes[v].dis % 2 == 0) {
            int pivot = nodes[v].dis / 2;
            for (i = 0; i < n; i++)
                if (nodes[i].dis == pivot)
                    res.push_back(i);
        }
        else {
            int pivot = nodes[v].dis / 2;
            for (i = 0; i < n; i++)
                if (nodes[i].dis == pivot || nodes[i].dis == pivot + 1)
                    res.push_back(i);
        }*/
        int len = list.size();
        if (len % 2 == 1)
            res.push_back(list[len / 2]);
        else {
            res.push_back(list[len / 2 - 1]);
            res.push_back(list[len / 2]);
        }
        delete[]nodes;
        return res;
    }
    bool createList(vector<int>& list, Node nodes[], int n, int start, int end) {
        nodes[start].visited = true;
        if (start == end) {
            list.push_back(end);
            return true;
        }
        int v, w;
        for (int i = 0; i < nodes[start].neighbors.size(); i++) {
            w = nodes[start].neighbors[i];
            if (!nodes[w].visited) {
                if (createList(list, nodes, n, w, end)) {
                    list.push_back(start);
                    return true;
                }
            }
        }
        return false;
    }
};