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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (!root)
            return 0;
        int result = 0;
        postorder(root, L, R, result);
        return result;
    }
    void postorder(TreeNode* root, int L, int R, int& result) {
        if (!root)
            return;
        if (root->val >= L && root->val <= R) {
            result = result + root->val;
            postorder(root->left, L, R, result);
            postorder(root->right, L, R, result);
        }
        else if (root->val < L) {
            postorder(root->right, L, R, result);
        }
        else
            postorder(root->left, L, R, result);
    }
};