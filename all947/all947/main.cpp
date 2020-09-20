#include <iostream>
using namespace std;
#include <vector>
#include <map>

class Solution1 {
private:
    int* parent;
    int find(int x) {
        while (parent[x] >= 0)
            x = parent[x];
        return x;
    }
    void Union(int x1, int x2) {
        int root1 = find(x1), root2 = find(x2);
        parent[root1] = parent[root1] + parent[root2];
        parent[root2] = root1;
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int len = stones.size();
        if (len < 2)
            return 0;
        parent = new int[len];
        memset(parent, -1, len * sizeof(int));
        map<int,int> x_coordinate;
        map<int, int> y_coordinate;
        for (int i = 0; i < len; i++) {
            bool have_neighbor = false;
            if (!x_coordinate.count(stones[i][0])) {
                x_coordinate[stones[i][0]] = i;
            }
            else {
                have_neighbor = true;
                Union(x_coordinate[stones[i][0]], i);
            }
            if (!y_coordinate.count(stones[i][1])) {
                y_coordinate[stones[i][1]] = i;
            }
            else if (!have_neighbor) {
                have_neighbor = true;
                Union(y_coordinate[stones[i][1]], i);
            }
        }
        int result = 0;
        for (int i = 0; i < len; i++) {
            if (parent[i] < -1)
                result += (-parent[i] - 1);
        }
        delete[]parent;
        return result;
    }
};

class Solution {
private:
    int find(vector<int>& parent,int x) {
        while (parent[x] >= 0)
            x = parent[x];
        return x;
    }
    void Union(vector<int>& parent, int x1, int x2) {
        int root1 = find(parent, x1), root2 = find(parent, x2);
        if (root1 == root2)
            return;
        parent[root1] = parent[root1] + parent[root2];
        parent[root2] = root1;
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int len = stones.size();
        if (len < 2)
            return 0;
        vector<int> parent(len, -1);
        map<int, int> x_coordinate;
        map<int, int> y_coordinate;
        for (int i = 0; i < len; i++) {
            if (!x_coordinate.count(stones[i][0])) {
                x_coordinate[stones[i][0]] = i;
            }
            else {
                Union(parent,x_coordinate[stones[i][0]], i);
            }
            if (!y_coordinate.count(stones[i][1])) {
                y_coordinate[stones[i][1]] = i;
            }
            else {
                Union(parent,y_coordinate[stones[i][1]], i);
            }
        }
        int result = 0;
        for (int i = 0; i < len; i++) {
            if (parent[i] < -1)
                result += (-parent[i] - 1);
        }
        return result;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> a = { {0,0},{0,1},{1,0},{1,2},{2,1},{2,2} };
    int re = sol.removeStones(a);
    return 0;
}