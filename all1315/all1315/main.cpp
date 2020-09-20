#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <algorithm>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        if (!root)
            return 0;
        int sum = 0;
        compute(root, sum, NULL);
        return sum;
    }
    void compute(TreeNode* root, int& sum,TreeNode* parent) {
        if (root->left) {
            if (parent && parent->val % 2 == 0)
                sum += root->left->val;
            compute(root->left, sum, root);
        }
        if (root->right) {
            if (parent && parent->val % 2 == 0)
                sum += root->right->val;
            compute(root->right, sum, root);
        }
    }
};