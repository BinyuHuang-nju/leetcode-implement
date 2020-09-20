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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size() == 0)
            return NULL;
        return createTree(preorder, 0, preorder.size() - 1);
    }
    TreeNode* createTree(vector<int>& preorder, int start, int end) {
        if (start > end)
            return NULL;
        else if (start == end)
            return new TreeNode(preorder[start]);
        TreeNode* root = new TreeNode(preorder[start]);
        int k;
        for (k = start + 1; k <= end; k++)
            if (preorder[k] > preorder[start])
                break;
        root->left = createTree(preorder, start + 1, k - 1);
        root->right = createTree(preorder, k, end);
        return root;
    }
};