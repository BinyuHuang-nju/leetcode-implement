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
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        if (!root->left && !root->right)
            return true;
        int h1 = Height(root->left), h2 = Height(root->right);
        if (abs(h1 - h2) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int Height(TreeNode* root) {
        if (root == NULL)
            return 0;
        if (height.count(root))
            return height[root];
        int h1 = Height(root->left), h2 = Height(root->right);
        height[root] = (h1 > h2 ? h1 : h2) + 1;
        return height[root];
    }
};