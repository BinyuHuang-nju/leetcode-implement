#include <iostream>
using namespace std;
#include <map>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    map<TreeNode*, int> height;
public:
    int findBottomLeftValue(TreeNode* root) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return root->val;
        return treeheight(root->left) >= treeheight(root->right) ? findBottomLeftValue(root->left) : findBottomLeftValue(root->right);
    }
    int treeheight(TreeNode* root) {
        if (!root)
            return 0;
        if (height[root] != 0)
            return height[root];
        int hl = treeheight(root->left), hr = treeheight(root->right);
        height[root] = 1 + (hl > hr ? hl : hr);
        return height[root];
    }
};