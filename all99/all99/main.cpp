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
    TreeNode* t1, * t2, * pre;
    void recoverTree(TreeNode* root) {
        t1 = t2 = pre = NULL;
        inorder(root);
        int temp = t1->val;
        t1->val = t2->val;
        t2->val = temp;
    }
    void inorder(TreeNode* root) {
        if (!root)
            return;
        if (root->left)
            inorder(root->left);
        if (pre && pre->val > root->val) {
            if (t1 == NULL)
                t1 = pre;
            t2 = root;
        }
        pre = root;
        if (root->right)
            inorder(root->right);
    }
};