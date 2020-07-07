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
    int minDiffInBST(TreeNode* root) {
        if (!root || (!root->left && !root->right))
            return 0;
        int min = 0, max = 0;
        return minDiff(root, min, max);
    }
    int minDiff(TreeNode* root, int& min, int& max) {
        if (!root->left && !root->right) {
            min = max = root->val;
            return INT_MAX;
        }
        else if (!root->right) {
            int diff = minDiff(root->left, min, max);
            int new_diff = root->val - max;
            max = root->val;
            return diff < new_diff ? diff : new_diff;
        }
        else if (!root->left) {
            int diff = minDiff(root->right, min, max);
            int new_diff = min - root->val;
            min = root->val;
            return diff < new_diff ? diff : new_diff;
        }
        else {
            int min1 = 0, min2 = 0, max1 = 0, max2 = 0;
            int diff1 = minDiff(root->left, min1, max1);
            int diff2 = minDiff(root->right, min2, max2);
            int new_diff = retmin(root->val - max1, min2 - root->val);
            min = min1;
            max = max2;
            return retmin(new_diff, retmin(diff1, diff2));
        }
        return 0;
    }
private:
    int retmin(int x, int y) {
        return x < y ? x : y;
    }
};