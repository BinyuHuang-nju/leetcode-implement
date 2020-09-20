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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if (pre.size() == 0)
            return NULL;
        if (pre.size() == 1)
            return new TreeNode(pre[0]);
        return createTree(pre, 0, pre.size() - 1, post, 0, post.size() - 1);
    }
    TreeNode* createTree(vector<int>& pre, int l1, int r1, vector<int>& post, int l2, int r2) {
        if (l1 > r1)
            return NULL;
        else if (l1 == r1)
            return new TreeNode(pre[l1]);
        TreeNode* root = new TreeNode(pre[l1]);
        int i;
        for (i = l2; i < r2; i++)
            if (pre[l1 + 1] == post[i])
                break;
        root->left = createTree(pre, l1 + 1, i - l2 + l1 + 1, post, l2, i);
        root->right = createTree(pre, i - l2 + l1 + 2, r1, post, i + 1, r2 - 1);
        return root;
    }
};