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
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> results;
        if (N % 2 == 0)
            return results;
        if (N == 1) {
            results.push_back(new TreeNode(0));
            return results;
        }
        for (int i = 1; i < N - 1; i = i + 2) {
            vector<TreeNode*> lefts = allPossibleFBT(i);
            vector<TreeNode*> rights = allPossibleFBT(N - 1 - i);
            for (TreeNode* left : lefts) {
                for (TreeNode* right : rights) {
                    TreeNode* root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    results.push_back(root);
                }
            }
        }
        return results;
    }
};