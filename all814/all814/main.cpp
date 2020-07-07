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
    TreeNode* pruneTree(TreeNode* root) {
        if (!root)
            return NULL;
        return prune(root);
    }
    TreeNode* prune(TreeNode* root) {
        if (!root)
            return NULL;
        if (root->left)
            root->left = prune(root->left);
        if (root->right)
            root->right = prune(root->right);
        if (!root->left && !root->right) {
            if (root->val == 0) {
                delete root;
                return NULL;
            }
        }
        return root;
    }
};