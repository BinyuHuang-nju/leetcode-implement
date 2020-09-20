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
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*> list;
        postOrder(list, root);
        if (list.size() <= 1)
            return root;
        for (int i = 0; i < list.size() - 1; i++) {
            list[i]->left = NULL;
            list[i]->right = list[i + 1];
        }
        return list[0];
    }
private:
    void postOrder(vector<TreeNode*>& list, TreeNode* root) {
        if (!root)
            return;
        postOrder(list, root->left);
        list.push_back(root);
        postOrder(list, root->right);
    }
};