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
    int rob(TreeNode* root) {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return root->val;
        if (root->right == NULL) {
            int chooseleft = rob(root->left);
            int notchoose = root->val + rob(root->left->left) + rob(root->left->right);
            return chooseleft > notchoose ? chooseleft : notchoose;
        }
        else if (root->left == NULL) {
            int chooseright = rob(root->right);
            int notchoose = root->val + rob(root->right->left) + rob(root->right->right);
            return chooseright > notchoose ? chooseright : notchoose;
        }
        int choosechild = rob(root->left) + rob(root->right);
        int notchoose = root->val + rob(root->left->left) + rob(root->left->right) + rob(root->right->left) + rob(root->right->right);
        return choosechild > notchoose ? choosechild : notchoose;
    }
};