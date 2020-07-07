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
    int findSecondMinimumValue(TreeNode* root) {
        if (!root || !root->left)
            return -1;
        return secondMin(root);
    }
    int secondMin(TreeNode* root) {
        if (!root->left)
            return -1;
        if (root->left->val < root->right->val)
            return root->right->val;
        else if (root->left->val > root->right->val)
            return root->left->val;
        int d1 = secondMin(root->left), d2 = secondMin(root->right);
        if (d1 == -1)
            return d2;
        if (d2 == -1)
            return d1;
        return d1 < d2 ? d1 : d2;
    }
};