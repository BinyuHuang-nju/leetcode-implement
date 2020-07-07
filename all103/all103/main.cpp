#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <stack>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution_fault {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        bool at_odd = true;
        queue<TreeNode*> queNode;
        TreeNode* tag = new TreeNode(0);
        queNode.push(root);
        queNode.push(tag);
        vector<int> cur;
        TreeNode* v;
        while (!queNode.empty()) {
            v = queNode.front();
            queNode.pop();
            cur.push_back(v->val);
            //
            if (queNode.front() == tag) {
                res.push_back(cur);
                at_odd = ~at_odd;
                cur.clear();
                queNode.pop();
                if(!queNode.empty())
                    queNode.push(tag);
            }
        }

    }
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        bool at_odd = true;
        stack<TreeNode*> stEven;
        stack<TreeNode*> stOdd;
        stOdd.push(root);
        vector<int> cur;
        TreeNode* p;
        while (!stOdd.empty()||!stEven.empty()) {
            if (at_odd) {
                p = stOdd.top();
                stOdd.pop();
                cur.push_back(p->val);
                if (p->left)
                    stEven.push(p->left);
                if (p->right)
                    stEven.push(p->right);
                if (stOdd.empty()) {
                    res.push_back(cur);
                    cur.clear();
                    at_odd = false;
                }
            }
            else {
                p = stEven.top();
                stEven.pop();
                cur.push_back(p->val);
                if (p->right)
                    stOdd.push(p->right);
                if (p->left)
                    stOdd.push(p->left);
                if (stEven.empty()) {
                    res.push_back(cur);
                    cur.clear();
                    at_odd = true;
                }
            }

        }
        return res;
    }
};