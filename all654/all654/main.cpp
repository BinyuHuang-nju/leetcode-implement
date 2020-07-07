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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0)
            return NULL;
        return createTree(nums, 0, nums.size() - 1);
    }
    TreeNode* createTree(vector<int>& nums, int p, int r) {
        if (p > r)
            return NULL;
        if (p == r)
            return new TreeNode(nums[p]);
        int max = nums[p], maxIndex = p;
        for(int i=p+1;i<=r;i++)
            if (max < nums[i]) {
                max = nums[i];
                maxIndex = i;
            }
        TreeNode* root = new TreeNode(max);
        root->left = createTree(nums, p, maxIndex - 1);
        root->right = createTree(nums, maxIndex + 1, r);
        return root;
    }
};