#include <iostream>
using namespace std;
#include <vector>

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root)
            return new TreeNode(val);
        TreeNode* parent = root;
        while (1) {
            if (parent->val < val) {
                if (parent->right)
                    parent = parent->right;
                else {
                    parent->right = new TreeNode(val);
                    break;
                }
            }
            else {
                if (parent->left)
                    parent = parent->left;
                else {
                    parent->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};