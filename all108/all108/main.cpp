#include<iostream>
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createTree(nums, 0, nums.size() - 1);
    }
    TreeNode* createTree(vector<int>& nums, int start, int end) {
        if (start > end)
            return NULL;
        if (start == end)
            return new TreeNode(nums[start]);
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = createTree(nums, start, mid - 1);
        root->right = createTree(nums, mid + 1, end);
        return root;
    }
};