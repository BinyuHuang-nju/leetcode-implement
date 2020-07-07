#include <iostream>
using namespace std;
#include <vector>
#include <string>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    string tree2str(TreeNode* t) {
        string res;
        if (!t)
            return res;
        return dfs(t);
    }
    string dfs(TreeNode* t) {
        string res = to_string(t->val);
        if (!t->left && !t->right) {
            return res;
        }
        else if (!t->right) {
            res += "(" + dfs(t->left) + ")";
        }
        else if (!t->left) {
            res += "()(" + dfs(t->right) + ")";
        }
        else {
            res += "(" + dfs(t->left) + ")(" + dfs(t->right) + ")";
        }
        return res;
    }
};