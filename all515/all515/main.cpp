#include <iostream>
using namespace std;
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
        queue<TreeNode*> queNode;
        int cur_max, num;
        bool first = true;
        TreeNode* p;
        queNode.push(root);
        while (!queNode.empty()) {
            num = queNode.size();
            p = queNode.front();
            queNode.pop();
            num--;
            cur_max = p->val;
            if (p->left)
                queNode.push(p->left);
            if (p->right)
                queNode.push(p->right);
            while (num) {
                num--;
                p = queNode.front();
                queNode.pop();
                if (p->val > cur_max)
                    cur_max = p->val;
                if (p->left)
                    queNode.push(p->left);
                if (p->right)
                    queNode.push(p->right);
            }
            res.push_back(cur_max);
        }
        return res;
    }
};