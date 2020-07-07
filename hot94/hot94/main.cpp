#include <iostream>
using namespace std;
#include <map>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root || (!root->left && !root->right))
            return 0;
        return diam(root);
    }
private:
    map<TreeNode*, int> treeheight;
    map<TreeNode*, int> treediam;
    int height(TreeNode* root) {
        if (root == NULL)
            return 0;
        if (treeheight[root] != 0)
            return treeheight[root];
        int h1 = height(root->left), h2 = height(root->right);
        treeheight[root] = 1 + (h1 > h2 ? h1 : h2);
        return treeheight[root];
    }
    int diam(TreeNode* root) {
        if (root == NULL)
            return 0;
        if (treediam[root] != 0)
            return treediam[root];
      /*  int children_num = 1;
        if (root->left && root->right)
            children_num = 2;
        else if (!root->left && !root->right)
            children_num = 0;*/
        int d1 = diam(root->left), d2 = diam(root->right);
        int h1 = height(root->left), h2 = height(root->right);
        treeheight[root] = 1 + (h1 > h2 ? h1 : h2);
        treediam[root] = max(d1, d2, h1 + h2);
        return treediam[root];
    }
    int max(int x, int y, int z) {
        int t = (x > y) ? x : y;
        return (t > z) ? t : z;
    }
};