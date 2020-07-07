#include <iostream>
using namespace std;
#include <vector>

class Solution {
private:
    struct Edge {
        int weight;
        int port;
    };
    struct Node {
        bool isSeen;
        int minedges;
        vector<Edge> points;
        Node() :isSeen(false), minedges(-1) {}
    };
    struct TreeNode {
        int tnode;
        int priority;
    };
    vector<TreeNode> heap;
    int* index;
    int currentSize;
private:
    void siftDown(int start, int m) {
        int i = start, j = 2 * i + 1;
        TreeNode temp = heap[i];
        while (j <= m) {
            if (j<m && heap[j].priority>heap[j + 1].priority)
                j++;
            if (temp.priority <= heap[j].priority)
                break;
            else {
                heap[i] = heap[j];
                index[heap[j].tnode] = i;
                i = j;
                j = 2 * j + 1;
            }
        }
        heap[i] = temp;
        index[temp.tnode] = i;
    }
    void siftUp(int start) {
        int j = start, i = (j - 1) / 2;
        TreeNode temp = heap[j];
        while (j > 0) {
            if (heap[i].priority <= temp.priority)
                break;
            else {
                heap[j] = heap[i];
                index[heap[i].tnode] = j;
                j = i;
                i = (i - 1) / 2;
            }
        }
        heap[j] = temp;
        index[temp.tnode] = j;
    }
    void Insert(int x, int x_size) {
        TreeNode node;
        node.tnode = x;
        node.priority = x_size;
        if (currentSize == heap.size()) {
            heap.emplace_back(node);
        }
        else {
            heap[currentSize] = node;
        }
        index[x] = currentSize;
        siftUp(currentSize);
        currentSize++;
    }
    void RemoveMin(TreeNode& x) {
        x = heap[0];
        index[heap[0].tnode] = -1;
        heap[0] = heap[currentSize - 1];
        index[heap[currentSize - 1].tnode] = 0;
        currentSize--;
        siftDown(0, currentSize - 1);
    }
    void DecreaseKey(int x, int x_size) {
        heap[index[x]].priority = x_size;
        siftUp(index[x]);
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        currentSize = 0;
        index = new int[N + 1];
        int i, v, w;
        Edge edge;
        for (i = 0; i <= N; i++)
            index[i] = -1;
        Node* nodes = new Node[N + 1]();
        for (i = 0; i < times.size(); i++) {
            v = times[i][0];
            edge.weight = times[i][2];
            edge.port = times[i][1];
            nodes[v].points.push_back(edge);
        }
        nodes[K].isSeen = true;
        nodes[K].minedges = 0;
        for (i = 0; i < nodes[K].points.size(); i++) {
            v = nodes[K].points[i].port;
            nodes[v].isSeen = true;
            Insert(v, nodes[K].points[i].weight);
        }
        TreeNode x;
        int newPriority, vw_weight, w_priority;
        while (currentSize) {
            RemoveMin(x);
            v = x.tnode;
            nodes[v].minedges = x.priority;
            for (i = 0; i < nodes[v].points.size(); i++) {
                w = nodes[v].points[i].port;
                vw_weight = nodes[v].points[i].weight;
                newPriority = nodes[v].minedges + vw_weight;
                if (!nodes[w].isSeen) {
                    nodes[w].isSeen = true;
                    Insert(w, newPriority);
                }
                else {
                    if (index[w] != -1 && newPriority < heap[index[w]].priority)
                        DecreaseKey(w, newPriority);
                }
            }
        }
        int longest = 0;
        for (i = 1; i <= N; i++) {
            if (nodes[i].minedges == -1)
                return -1;
            if (nodes[i].minedges > longest)
                longest = nodes[i].minedges;
        }
        delete[]nodes;
        return longest;
    }
};