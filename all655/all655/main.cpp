#include <iostream>
using namespace std;
#include <vector>
#include <string>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int d = depth(root);
        int h = (1 << d) - 1;
        vector<vector<string>> results(d, vector<string>(h, ""));
        if (d == 0)
            return results;
        fillNode(root, results, 0, h - 1, 0);
        return results;
    }
    void fillNode(TreeNode* root, vector<vector<string>>& results, \
        int l, int r, int curd) {
        int mid = (l + r) / 2;
        results[curd][mid] = to_string(root->val);
        if (root->left)
            fillNode(root->left, results, l, mid - 1, curd + 1);
        if (root->right)
            fillNode(root->right, results, mid + 1, r, curd + 1);
    }
    int depth(TreeNode* root) {
        if (!root)
            return 0;
        int d1 = depth(root->left), d2 = depth(root->right);
        return (d1 > d2 ? d1 : d2) + 1;
    }
};