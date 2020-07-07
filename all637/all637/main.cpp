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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> results;
        if (!root)
            return results;
        double sum = 0.0;
        int num = 0;
        TreeNode* p;
        queue<TreeNode*> que;
        TreeNode* tag = new TreeNode(-1);
        que.push(root);
        que.push(tag);
        while (!que.empty()) {
            p = que.front();
            que.pop();
            sum += (double)p->val;
            num++;
            if (p->left)
                que.push(p->left);
            if (p->right)
                que.push(p->right);
            if (!que.empty() && que.front() == tag) {
                que.pop();
                results.push_back(sum / num);
                sum = 0.0;
                num = 0;
                if (!que.empty())
                    que.push(tag);
            }
        }
        return results;
    }
};