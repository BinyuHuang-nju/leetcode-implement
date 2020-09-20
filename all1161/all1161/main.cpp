#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <algorithm>
 struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        TreeNode* tag = new TreeNode(-1);
        queue<TreeNode*> queNode;
        queNode.push(root);
        queNode.push(tag);
        int maxElem = root->val, maxDepth = 1;
        int curElem = 0, curDepth = 1;
        TreeNode* p;
        while (!queNode.empty()) {
            p = queNode.front();
            queNode.pop();
            curElem += p->val;
            if (p->left)
                queNode.push(p->left);
            if (p->right)
                queNode.push(p->right);
            if (!queNode.empty() && queNode.front() == tag) {
                queNode.pop();
                if (curElem > maxElem) {
                    maxElem = curElem;
                    maxDepth = curDepth;
                }
                if (!queNode.empty()) {
                    curElem = 0;
                    curDepth++;
                    queNode.push(tag);
                }
            }
        }
        return maxDepth;
    }
};
int main() {
    TreeNode* p1 = new TreeNode(1);
    TreeNode* p2 = new TreeNode(7);
    TreeNode* p3 = new TreeNode(0);
    TreeNode* p4 = new TreeNode(7);
    TreeNode* p5 = new TreeNode(-8);
    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    Solution sol;
    sol.maxLevelSum(p1);
    return 0;
}