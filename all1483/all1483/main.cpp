#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class TreeAncestor1 {
private:
    int n;
    vector<int> parent;
public:
    TreeAncestor1(int n, vector<int>& parent) {
        this->n = n;
        this->parent = parent;
    }

    int getKthAncestor(int node, int k) {
        while (k > 0 && node >= 0) {
            node = parent[node];
            k--;
        }
        return node;
    }
};

class TreeAncestor {
private:
    int n;
    vector<vector<int>> dp;
public:
    TreeAncestor(int n, vector<int>& parent) {
        this->n = n;
        dp = vector<vector<int>>(n, vector<int>(log2(n) + 1, -1));
        for (int i = 0; i < n; i++)
            dp[i][0] = parent[i];
        for (int j = 1; (1 << j) < n; j++) {
            for (int i = 0; i < n; i++) {
                if (dp[i][j - 1] != -1)
                    dp[i][j] = dp[dp[i][j - 1]][j - 1];
            }
        }
    }

    int getKthAncestor(int node, int k) {
        if (k == 0 || node == -1)
            return node;
        int m = log2(k);
        return getKthAncestor(dp[node][m], k - (1 << m));
    }
};

int main() {
    vector<int> p = { -1,0,0,1,1,2,2 };
    TreeAncestor tree(7, p);
    int a=tree.getKthAncestor(3, 1);
    int b=tree.getKthAncestor(5, 2);
    int c=tree.getKthAncestor(6, 3);
    return 0;
}