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
private:
    int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
public:
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();
        int size = N * N;
        currentSize = 0;
        index = new int[size];
        int i, j, v, w;
        int new_i, new_j;
        Edge edge;
        for (i = 0; i < size; i++)
            index[i] = -1;
        Node* nodes = new Node[size]();
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                v = i * N + j;
                for (int k = 0; k < 4; k++) {
                    new_i = i + dir[k][0];
                    new_j = j + dir[k][1];
                    if (new_i >= 0 && new_i < N && new_j >= 0 && new_j < N) {
                        if (grid[i][j] < grid[new_i][new_j])
                            edge.weight = grid[new_i][new_j] - grid[i][j];
                        else
                            edge.weight = 0;
                        edge.port = new_i * N + new_j;
                        nodes[v].points.push_back(edge);
                    }
                }
            }
        }
        nodes[0].isSeen = true;
        nodes[0].minedges = grid[0][0];
        for (i = 0; i < nodes[0].points.size(); i++) {
            v = nodes[0].points[i].port;
            nodes[v].isSeen = true;
            Insert(v, grid[0][0] + nodes[0].points[i].weight);
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
        
        int ret = nodes[size - 1].minedges;
        delete[]nodes;
        return ret;
    
    }
};