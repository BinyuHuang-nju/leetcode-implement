#include <iostream>
using namespace std;
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* p = new TreeNode(v);
            p->left = root;
            return p;
        }
        queue<TreeNode*> queNode;
        TreeNode* tag = new TreeNode(-1);
        int depth = 1;
        queNode.push(root);
        queNode.push(tag);
        TreeNode* p;
        while (!queNode.empty()) {
            p = queNode.front();
            queNode.pop();
            if (depth == d - 1) {
                TreeNode* p1 = new TreeNode(v);
                TreeNode* p2 = new TreeNode(v);
                p1->left = p->left;
                p2->right = p->right;
                p->left = p1;
                p->right = p2;
            }
            else {
                if (p->left)
                    queNode.push(p->left);
                if (p->right)
                    queNode.push(p->right);
            }
            if (!queNode.empty() && queNode.front() == tag) {
                if (depth == d - 1)
                    break;
                queNode.pop();
                if (!queNode.empty()) {
                    queNode.push(tag);
                    depth++;
                }
            }
        }
        return root;
    }
};