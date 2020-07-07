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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int curnum = 1, maxnum = 0;
        TreeNode* pre = NULL;
        inorder(root, pre, curnum, maxnum, res);
        return res;
    }
    void inorder(TreeNode* root, TreeNode*& pre, int& curnum, int& maxnum, vector<int>& res) {
        if (!root)
            return;
        inorder(root->left, pre, curnum, maxnum, res);
        if (pre) {
            curnum = (pre->val == root->val) ? curnum + 1 : 1;
        }
        if (curnum == maxnum) {
            res.push_back(root->val);
        }
        else if (curnum > maxnum) {
            res.clear();
            maxnum = curnum;
            res.push_back(root->val);
        }
        pre = root;
        inorder(root->right, pre, curnum, maxnum, res);
    }
};