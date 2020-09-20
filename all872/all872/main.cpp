#include <iostream>
using namespace std;
#include <queue>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2)
            return true;
        if (!root1 || !root2)
            return false;
        //queue<TreeNode*> que1, que2;
        vector<int> results1, results2;
        /*
        TreeNode* p;
        que1.push(root1);
        while (!que1.empty()) {
            p = que1.front();
            que1.pop();
            if (!p->left && !p->right)
                results1.push_back(p->val);
            if (p->left)
                que1.push(p->left);
            if (p->right)
                que1.push(p->right);
        }
        que2.push(root2);
        while (!que2.empty()) {
            p = que2.front();
            que2.pop();
            if (!p->left && !p->right)
                results2.push_back(p->val);
            if (p->left)
                que2.push(p->left);
            if (p->right)
                que2.push(p->right);
        }*/
        increaseLeaf(root1, results1);
        increaseLeaf(root2, results2);
        if (results1.size() != results2.size())
            return false;
        for (int i = 0; i < results1.size(); i++) {
            if (results1[i] != results2[i])
                return false;
        }
        return true;
    }
private:
    void increaseLeaf(TreeNode* root, vector<int>& results) {
        if (!root)
            return;
        if (!root->left && !root->right)
            results.push_back(root->val);
        else {
            increaseLeaf(root->left, results);
            increaseLeaf(root->right, results);
        }
    }
};