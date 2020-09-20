#include <iostream>
using namespace std;
#include <vector>
#include <map>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> results;
        if (!root)
            return results;
        map<int, int> mp;
        for (int d : to_delete)
            mp[d] = 1;
        postorder(results, root, NULL, mp);
        if (!mp.count(root->val))
            results.push_back(root);
        return results;
    }
    void postorder(vector<TreeNode*>& results, TreeNode* root, TreeNode* parent, map<int, int>& mp) {
        if (!root)
            return;
        postorder(results, root->left, root, mp);
        postorder(results, root->right, root, mp);
        if (mp.count(root->val)) {
            if (parent && parent->left == root)
                parent->left = NULL;
            if (parent && parent->right == root)
                parent->right = NULL;
            if (root->left)
                results.push_back(root->left);
            if (root->right)
                results.push_back(root->right);
        }
    }
};