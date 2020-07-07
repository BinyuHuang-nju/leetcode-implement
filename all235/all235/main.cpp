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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;
        while (cur) {
            if ((cur->val - p->val) * (cur->val - q->val) <= 0)
                return cur;
            else if (cur->val > p->val)
                cur = cur->left;
            else
                cur = cur->right;
        }
        return NULL;
    }
};