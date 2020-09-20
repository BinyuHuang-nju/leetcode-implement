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
    bool isCompleteTree(TreeNode* root) {
        if (!root)
            return true;
        queue<TreeNode*> que;
        int curSum = 1, tag = 1;
        TreeNode* p;
        que.push(root);
        while (!que.empty()) {
            curSum = 0;
            bool isEnd = false;
            for (int i = 0; i < tag; i++) {
                p = que.front();
                que.pop();
                if (isEnd && (p->left || p->right))
                    return false;
                if (!p->left && p->right)
                    return false;
                if (p->left && p->right) {
                    curSum += 2;
                    que.push(p->left);
                    que.push(p->right);
                }
                else {
                    isEnd = true;
                    if (p->left) {
                        curSum++;
                        que.push(p->left);
                    }
                }
            }
            tag = tag * 2;
            if (curSum < tag) {
                for (int i = 0; i < curSum; i++) {
                    p = que.front();
                    que.pop();
                    if (p->left || p->right)
                        return false;
                }
                return true;
            }
        }
        return true;
    }
};