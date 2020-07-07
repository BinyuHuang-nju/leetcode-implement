#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <cstring>

 struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} 
};
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root)
            return res;
        vector<int> cur;
        dfs(res, cur, root);
        return res;
    }
    void dfs(vector<string>& res, vector<int>& cur, TreeNode* root) {
        cur.push_back(root->val);
        if (!root->left && !root->right) {
            string str = to_string(cur[0]);
            for (int i = 1; i < cur.size(); i++)
                str = str + "->" + to_string(cur[i]);
            res.push_back(str);
        }
        else {
            if (root->left)
                dfs(res, cur, root->left);
            if (root->right)
                dfs(res, cur, root->right);
        }
        cur.pop_back();
    }
};