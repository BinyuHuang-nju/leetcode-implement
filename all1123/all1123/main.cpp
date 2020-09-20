#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    map<TreeNode*, TreeNode*> parent;
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root)
            return NULL;
        queue<TreeNode*> queNode;
        vector<TreeNode*> deepestNodes;
        TreeNode* tag = new TreeNode(-1);
        TreeNode* p;
        parent[root] = NULL;
        queNode.push(root);
        queNode.push(tag);
        //deepestNodes.push_back(root);
        while (!queNode.empty()) {
            p = queNode.front();
            deepestNodes.push_back(p);
            queNode.pop();
            if (p->left) {
                queNode.push(p->left);
                //deepestNodes.push_back(p->left);
                parent[p->left] = p;
            }
            if (p->right) {
                queNode.push(p->right);
                //deepestNodes.push_back(p->right);
                parent[p->right] = p;
            }
            if (!queNode.empty() && queNode.front() == tag) {
                queNode.pop();
                if (!queNode.empty()) {
                    deepestNodes.clear();
                    queNode.push(tag);
                }
            }
        }
        if (deepestNodes.size() == 1)
            return deepestNodes[0];
        while (deepestNodes.size() > 1) {
            vector<TreeNode*> temp;
            for (TreeNode* node : deepestNodes) {
                if (temp.size() == 0 || temp[temp.size() - 1] != parent[node])
                    temp.push_back(parent[node]);
            }
            deepestNodes = temp;
        }
        return deepestNodes[0];
    }
};

class Solution {
private:
    map<TreeNode*, int> depth;
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root)
            return NULL;
        computeDepth(root);
        TreeNode* p = root;
        while (p) {
            if (p->left && p->right) {
                if (depth[p->left] == depth[p->right])
                    return p;
                else if (depth[p->left] > depth[p->right])
                    p = p->left;
                else
                    p = p->right;
            }
            else if (p->left)
                p = p->left;
            else if (p->right)
                p = p->right;
            else
                return p;
        }
        return NULL;
    }
    int computeDepth(TreeNode* root){
        if (!root)
            return 0;
        int l = computeDepth(root->left), r = computeDepth(root->right);
        depth[root] = max(l, r) + 1;
        return depth[root];
    }
};

int main() {
    Solution sol;
    TreeNode* p1 = new TreeNode(1);
    TreeNode* p2 = new TreeNode(2);
    TreeNode* p3 = new TreeNode(3);
    TreeNode* p4 = new TreeNode(4);
    TreeNode* p5 = new TreeNode(5);
    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    sol.lcaDeepestLeaves(p1);
    return 0;
}