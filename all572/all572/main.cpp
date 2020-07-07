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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s && !t)
            return true;
        if (!s)
            return false;
        return subtree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    bool subtree(TreeNode* root, TreeNode* cur) {
        if (!root && !cur)
            return true;
        if (!root || !cur)
            return false;

        if (root->val == cur->val) {
            if (subtree(root->left, cur->left) && subtree(root->right, cur->right))
                return true;
        }

        return false;
    }
};