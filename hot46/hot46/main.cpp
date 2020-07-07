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
    int maxPathSum(TreeNode* root) {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return root->val;
        int leftdepth = maxDepth(root->left), rightdepth = maxDepth(root->right);
        int cur = root->val;
        if (leftdepth > 0)
            cur += leftdepth;
        if (rightdepth > 0)
            cur += rightdepth;
        int tmp;
        if (root->left != NULL && root->right != NULL) {
            int leftpath = maxPathSum(root->left), rightpath = maxPathSum(root->right);
            tmp = leftpath > rightpath ? leftpath : rightpath;
        }
        else if (root->left != NULL) {
            tmp = maxPathSum(root->left);
        }
        else {
            tmp = maxPathSum(root->right);
        }
        return cur > tmp ? cur : tmp;
    }
private:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return root->val;
        else if (root->left == NULL) {
            int tmp = maxDepth(root->right);
            return tmp > 0 ? root->val + tmp : root->val;
        }
        else if (root->right == NULL) {
            int tmp = maxDepth(root->left);
            return tmp > 0 ? root->val + tmp : root->val;
        }
        else {
            int tmp1 = maxDepth(root->left), tmp2 = maxDepth(root->right);
            if (tmp1 <= 0 && tmp2 <= 0)
                return root->val;
            int tmp = tmp1 > tmp2 ? tmp1 : tmp2;
            return root->val + tmp;
        }
    }
};