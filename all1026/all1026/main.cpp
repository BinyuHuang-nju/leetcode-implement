#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        int a = 0, b = 0;
        return maxDiff(root, a, b);
    }
    int maxDiff(TreeNode* root, int& submin, int& submax) {
        if (!root)
            return 0;
        if (!root->left && !root->right) {
            submin = submax = root->val;
            return 0;
        }
        else if (!root->right) {
            int x = 0, y = 0;
            int l = maxDiff(root->left, x, y);
            int result = max(abs(root->val - x), abs(root->val - y));
            result = max(result, l);
            submin = min(root->val, x);
            submax = max(root->val, y);
            return result;
        }
        else if (!root->left) {
            int x = 0, y = 0;
            int r = maxDiff(root->right, x, y);
            int result = max(abs(root->val - x), abs(root->val - y));
            result = max(result, r);
            submin = min(root->val, x);
            submax = max(root->val, y);
            return result;
        }
        int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
        int l = maxDiff(root->left, x1, y1), r = maxDiff(root->right, x2, y2);
        l = max(l, r);
        x1 = min(x1, x2);
        y1 = max(y1, y2);
        int result = max(abs(root->val - x1), abs(root->val - y1));
        result = max(result, l);
        submin = min(root->val, x1);
        submax = max(root->val, y1);
        return result;
    }
};