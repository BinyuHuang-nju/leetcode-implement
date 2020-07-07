#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        int l1 = minDepth(root->left), l2 = minDepth(root->right);
        if (l1 == 0 || l2 == 0)
            return (l1 == 0 ? l2 : l1) + 1;
        return (l1 > l2 ? l2 : l1) + 1;
    }
};