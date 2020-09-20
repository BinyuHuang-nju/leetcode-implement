#include <iostream>
using namespace std;
#include <vector>
#include <queue>
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
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root || root->val == x || root->val == y)
            return false;
        queue<TreeNode*> queNode;
        TreeNode* tag = new TreeNode(-1);
        queNode.push(root);
        queNode.push(tag);
        TreeNode* p;
        bool findFirst = false;
        while (!queNode.empty()) {
            p = queNode.front();
            queNode.pop();
            if (p->left) {
                if (p->left->val == x || p->left->val == y) {
                    if (findFirst)
                        return true;
                    findFirst = true;
                }
                queNode.push(p->left);
            }
            if (p->right) {
                if (p->right->val == x || p->right->val == y) {
                    if (findFirst) {
                        if (p->left && (p->left->val == x || p->left->val == y))
                            return false;
                        return true;
                    }
                    findFirst = true;
                }
                queNode.push(p->right);
            }
            if (!queNode.empty() && queNode.front() == tag) {
                queNode.pop();
                if (findFirst)
                    return false;
                queNode.push(tag);
            }
        }
        return false;
    }
};