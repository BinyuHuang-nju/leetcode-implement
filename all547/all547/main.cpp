#include <iostream>
using namespace std;
#include <vector>
class UFSet {
private:
    vector<int> parent;
public:
    UFSet(int size) {
        for (int i = 0; i < size; i++)
            parent.push_back(-1);
    }
    int Find(int x) {
        while (parent[x] >= 0)
            x = parent[x];
        return x;
    }
    void Union(int i, int j) {
        if (Find(i) == Find(j))
            return;
        int root1 = Find(i), root2 = Find(j);
        parent[root1] = parent[root1] + parent[root2];
        parent[root2] = root1;
    }
    int group() {
        int res = 0;
        for (int i = 0; i < parent.size(); i++)
            if (parent[i] < 0)
                res++;
        return res;
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        UFSet set(M.size());
        int i, j;
        for (i = 1; i < M.size(); i++) {
            for (j = 0; j < i; j++) {
                if (M[i][j] == 1)
                    set.Union(i, j);
            }
        }
        return set.group();
    }
};
int main() {
    Solution sol;
    vector<vector<int>> a = { {1,1,1,1,1},{1,1,1,1,1}, {1,1,1,1,1}, {1,1,1,1,1}, {1,1,1,1,1}};
    cout << sol.findCircleNum(a);
    return 0;
}