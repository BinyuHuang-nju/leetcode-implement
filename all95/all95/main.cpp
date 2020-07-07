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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if (n == 0)
            return res;
        return generate(1, n);
    }
    vector<TreeNode*> generate(int left, int right) {
        vector<TreeNode*> res;
        if (left > right) {
            res.push_back(NULL);
            return res;
        }
        for (int i = left; i <= right; i++) {
            vector<TreeNode*> l = generate(left, i - 1);
            vector<TreeNode*> r = generate(i + 1, right);
            for (TreeNode* ltree : l) {
                for (TreeNode* rtree : r) {
                    TreeNode* root = new TreeNode(i);
                    root->left = ltree;
                    root->right = rtree;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};