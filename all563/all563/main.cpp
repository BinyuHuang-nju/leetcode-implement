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
    int findTilt(TreeNode* root) {
        if (!root)
            return 0;
        int res = 0;
        compute(root, res);
        return res;
    }
    int compute(TreeNode* root, int& res) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return root->val;
        int l = compute(root->left, res);
        int r = compute(root->right, res);
        res = res + abs(l - r);
        return l + r + root->val;
    }
};