#include <iostream>
using namespace std;
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL)
            return res;
        inorder(root, res);
        return res;
    }
private:
    void inorder(TreeNode* root, vector<int>& res) {
        if (root->left != NULL)
            inorder(root->left, res);
        res.push_back(root->val);
        if (root->right != NULL)
            inorder(root->right, res);
    }
};