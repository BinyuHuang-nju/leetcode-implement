#include <iostream>
using namespace std;
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        if (!root)
            return 0;
        queue<int> que;
        inorder(que, root);
        int first = que.front();
        que.pop();
        int second = que.front();
        que.pop();
        int diff = second - first;
        first = second;
        while (!que.empty()) {
            second = que.front();
            que.pop();
            if (second - first < diff)
                diff = second - first;
            first = second;
        }
        return diff;
    }
    void inorder(queue<int>& que, TreeNode* root) {
        if (root->left)
            inorder(que, root->left);
        que.push(root->val);
        if (root->right)
            inorder(que, root->right);
    }
};