#include <iostream>
using namespace std;
#include <vector>
#include <string>
class Solution {
private:
    vector<int> parent;
    int Find(int x) {
        while (parent[x] >= 0)
            x = parent[x];
        return x;
    }
    void Union_root(int root1, int root2) {
        parent[root1] = parent[root1] + parent[root2];
        parent[root2] = root1;
    }
    void Union_node(int x1, int x2) {
        int root1 = Find(x1), root2 = Find(x2);
        if (root1 == root2)
            return;
        parent[root1] = parent[root1] + parent[root2];
        parent[root2] = root1;
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int size = grid.size();
        const int N = size + 1;
        parent = vector<int>(N * N, -1);
        for (int j = 0; j < N; j++) {
            Union_node(0, j);
            Union_node(0, N * (N - 1) + j);
        }
        for (int i = 1; i < N - 1; i++) {
            Union_node(0, i * N);
            Union_node(0, i * N + N - 1);
        }
        int result = 1;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (grid[i][j] == '/') {
                    int root1 = Find((i + 1) * N + j), root2 = Find(i * N + (j + 1));
                    if (root1 == root2)
                        result++;
                    else
                        Union_root(root1, root2);
                }
                else if (grid[i][j] == '\\') {
                    int root1 = Find(i * N + j), root2 = Find((i + 1) * N + (j + 1));
                    if (root1 == root2)
                        result++;
                    else
                        Union_root(root1, root2);
                }
            }
        }
        return result;
    }
};