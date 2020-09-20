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
public:
    int pseudoPalindromicPaths(TreeNode* root) {
        if (!root)
            return 0;
        int result = 0;
        vector<int> nums(10, 0);
        dfs(root, result, nums);
        return result;
    }
    void dfs(TreeNode* root, int& result, vector<int>& nums) {
        if (!root->left && !root->right) {
            nums[root->val]++;
            int odd = 0;
            for (int i = 1; i <= 9; i++)
                if (nums[i] % 2 == 1)
                    odd++;
            if (odd < 2)
                result++;
        }
        else {
            if (root->left) {
                vector<int> tmp = nums;
                tmp[root->val]++;
                dfs(root->left, result, tmp);
            }
            if (root->right) {
                vector<int> tmp = nums;
                tmp[root->val]++;
                dfs(root->right, result, tmp);
            }
        }
    }
};