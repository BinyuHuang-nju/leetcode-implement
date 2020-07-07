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
    TreeNode* bstToGst(TreeNode* root) {
        if (!root)
            return NULL;
        int cur = 0;
        changeVal(root, cur);
        return root;
    }
    void changeVal(TreeNode* root, int& cur) {
        if (root->right)
            changeVal(root->right, cur);
        cur = cur + root->val;
        root->val = cur;
        if (root->left)
            changeVal(root->left, cur);
    }
};