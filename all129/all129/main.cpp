#include <iostream>
using namespace std;
#include <vector>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return root->val;
        int res = 0;
        dfs(res, root, 0);
        return res;
    }
    void dfs(int& res, TreeNode* root, int cur) {
        cur = cur * 10 + root->val;
        if (!root->left && !root->right)
            res = res + cur;
        else {
            if (root->left)
                dfs(res, root->left, cur);
            if (root->right)
                dfs(res, root->right, cur);
        }
    }
};
int main() {
    Solution sol;
    TreeNode* p1 = new TreeNode(1);
    TreeNode* p2 = new TreeNode(2);
    TreeNode* p3 = new TreeNode(3);
    p1->left = p2;
    p1->right = p3;
    cout << sol.sumNumbers(p1);
    return 0;
}