#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int goodNodes(TreeNode* root) {
        if (!root)
            return 0;
        return nodes(root, root->val - 1);
    }
    int nodes(TreeNode* root, int premax) {
        if (!root)
            return 0;
        if (premax > root->val) {
            return nodes(root->left, premax) + nodes(root->right, premax);
        }
        return 1 + nodes(root->left, root->val) + nodes(root->right, root->val);
    }
};