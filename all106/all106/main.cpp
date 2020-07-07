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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0)
            return NULL;
        return dfs(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    TreeNode* dfs(vector<int>& inorder, int l1, int h1, vector<int>& postorder, int l2, int h2) {
        if (l1 > h1)
            return NULL;
        if (l1 == h1)
            return new TreeNode(inorder[l1]);
        int pivot;
        for (pivot = l1; pivot <= h1; pivot++)
            if (inorder[pivot] == postorder[h2])
                break;
        TreeNode* root = new TreeNode(postorder[h2]);
        TreeNode* left = dfs(inorder, l1, pivot - 1, postorder, l2, l2 - l1 + pivot - 1);
        TreeNode* right = dfs(inorder, pivot + 1, h1, postorder, l2 - l1 + pivot, h2 - 1);
        root->left = left;
        root->right = right;
        return root;
    }
};
int main() {
    Solution sol;
    vector<int> a = { 9,3,15,20,7 }, b = { 9,15,7,20,3 };
    TreeNode* p = sol.buildTree(a, b);
    return 0;
}