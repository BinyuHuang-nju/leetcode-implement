#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <stack>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        queue<TreeNode*> queNode;
        stack<TreeNode*> stNode;
        TreeNode* tag = new TreeNode(-1);
        queNode.push(root);
        queNode.push(tag);
        stNode.push(tag);
        stNode.push(root);
        stNode.push(tag);
        vector<int> cur;
        TreeNode* p;
        while (!queNode.empty()) {
            p = queNode.front();
            queNode.pop();
            if (p->right) {
                queNode.push(p->right);
                stNode.push(p->right);
            }
            if (p->left) {
                queNode.push(p->left);
                stNode.push(p->left);
            }
            if (!queNode.empty() && queNode.front() == tag) {
                queNode.pop();
                if (!queNode.empty()) {
                    queNode.push(tag);
                    stNode.push(tag);
                }
            }
        }
        stNode.pop();
        while (!stNode.empty()) {
            p = stNode.top();
            stNode.pop();
            cur.push_back(p->val);
            if (!stNode.empty() && stNode.top() == tag) {
                res.push_back(cur);
                cur.clear();
                stNode.pop();
            }
        }
        return res;
    }
};