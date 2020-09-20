#include <iostream>
using namespace std;
#include <vector>
#include <string>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution { //merge
public:
    string smallestFromLeaf(TreeNode* root) {
        if (!root)
            return "";
        string v(1, root->val + 'a');
        if (!root->left && !root->right)
            return v;
        else if (!root->right)
            return smallestFromLeaf(root->left) + v;
        else if (!root->left)
            return smallestFromLeaf(root->right) + v;
        string a = smallestFromLeaf(root->left)+v, b = smallestFromLeaf(root->right)+v;
        if (a < b)
            return a;
        return b;
    }
};