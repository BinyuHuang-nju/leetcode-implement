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
    TreeNode* convertBST(TreeNode* root) {
        if (root == NULL)
            return NULL;
        int cur = 0;
        compute(root, cur);
        return root;
    }
private:
    void compute(TreeNode* root, int& cur) {
        if (root->right)
            compute(root->right, cur);
        root->val = root->val + cur;
        cur = root->val;
        if (root->left)
            compute(root->left, cur);
    }
};