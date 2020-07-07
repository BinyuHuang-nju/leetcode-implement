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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == NULL)
            return res;
        TreeNode* last = new TreeNode(0);
        queue<TreeNode*> queNode;
        queNode.push(root);
        queNode.push(last);
        TreeNode* p;
        while (!queNode.empty()) {
            p = queNode.front();
            queNode.pop();
            if (p->left)
                queNode.push(p->left);
            if (p->right)
                queNode.push(p->right);
            if (!queNode.empty() && queNode.front() == last) {
                res.push_back(p->val);
                queNode.pop();
                if(!queNode.empty())
                    queNode.push(last);
            }
        }
        return res;
    }
};