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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
private:
    TreeNode* buildTree(vector<int>& pre, int h1, int t1, vector<int>& in, int h2, int t2) {
        if (h1 > t1)
            return NULL;
        if (h1 == t1)
            return new TreeNode(pre[h1]);
        int k;
        for (k = h2; k <= t2; k++)
            if (pre[h1] == in[k])
                break;
        TreeNode* cur = new TreeNode(pre[h1]);
        cur->left = buildTree(pre, h1 + 1, h1 + k - h2, in, h2, k - 1);
        cur->right = buildTree(pre, h1 + k - h2 + 1, t1, in, k + 1, t2);
        return cur;
    }
};