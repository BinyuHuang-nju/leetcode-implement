#include <iostream>
using namespace std;
#include <vector>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution_112 {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root)
            return false;
        if (!root->left && !root->right)
            return (sum == root->val);
        bool h1 = false, h2 = false;
        if (root->left)
            h1 = hasPathSum(root->left, sum - root->val);
        if (root->right)
            h2 = hasPathSum(root->right, sum - root->val);
        return h1 || h2;
    }
};
class Solution_113 {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> cur;
        if (!root)
            return res;
        hasPathSum(root, sum, res, cur);
        return res;
    }

    void hasPathSum(TreeNode* root, int sum, \
        vector<vector<int>>& res, vector<int>& cur) {
        cur.push_back(root->val);
        if (!root->left && !root->right) {
            if (sum == root->val) {
                res.push_back(cur);
            }
        }
        else {
            if (root->left)
                hasPathSum(root->left, sum - root->val, res, cur);
            if (root->right)
                hasPathSum(root->right, sum - root->val, res, cur);
        }
        cur.pop_back();
    }
};