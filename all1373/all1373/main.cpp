#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
private:
    int maxtree;
public:
    int maxSumBST(TreeNode* root) {
        maxtree = 0;
        int curmin = 0, curmax = 0;
        subtree(root, curmin, curmax);
        return maxtree;
    }
private:
        int subtree(TreeNode* root,int& curmin,int& curmax) {
        if (!root)
            return 0;
        if (!root->left && !root->right) {
            maxtree = max(maxtree, root->val);
            curmin = curmax = root->val;
            return root->val;
        }
        int min1 = 0, min2 = 0, max1 = 0, max2 = 0;
        int l = subtree(root->left, min1, max1), r = subtree(root->right, min2, max2);
        if ( l == INT_MIN || r == INT_MIN||(root->left&& max1 >= root->val) || (root->right && min2 <= root->val))
            return INT_MIN;
        if (root->left)
            curmin = min1;
        else
            curmin = root->val;
        if (root->right)
            curmax = max2;
        else
            curmax = root->val;
        maxtree = max(maxtree, root->val + l + r);
        return root->val + l + r;
    }
};
int main() {
    Solution sol;
    TreeNode* p1 = new TreeNode(1);
    TreeNode* p2 = new TreeNode(5);
    TreeNode* p3 = new TreeNode(10);
    TreeNode* p4 = new TreeNode(7);
    TreeNode* p5 = new TreeNode(5);
    TreeNode* p6 = new TreeNode(10);
    TreeNode* p7 = new TreeNode(7);
    TreeNode* p8 = new TreeNode(9);
    p1->right = p2;
    p2->left = p3;
    p2->right = p4;
    p4->left = p5;
    p4->right = p6;
    p5->right = p7;
    p7->right = p8;
    int result = sol.maxSumBST(p1);
    return 0;
}