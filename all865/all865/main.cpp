#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <map>

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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root)
            return NULL;
        queue<TreeNode*> queNode;
        parent[root] = NULL;
        vector<TreeNode*> minNodes;

        TreeNode* tag = new TreeNode(-1);
        queNode.push(root);
        queNode.push(tag);
        TreeNode* p;
        while (!queNode.empty()) {
            p = queNode.front();
            queNode.pop();
            minNodes.push_back(p);
            if (p->left) {
                queNode.push(p->left);
                parent[p->left] = p;
            }
            if (p->right) {
                queNode.push(p->right);
                parent[p->right] = p;
            }
            if (!queNode.empty() && queNode.front() == tag) {
                queNode.pop();
                if (!queNode.empty()) {
                    minNodes.clear();
                    queNode.push(tag);
                }
            }
        }
        queue<TreeNode*> results1;
        for (TreeNode* node : minNodes) {
            results1.push(node);
        }
        if (results1.size() == 1)
            return results1.front();
        while (!results1.empty()) {
            vector<TreeNode*> results2;
            while (!results1.empty()) {
                p = results1.front();
                results1.pop();
                if (results2.empty() || results2[0] != parent[p])
                    results2.push_back(parent[p]);
            }
            if (results2.size() == 1)
                return results2[0];
            for (TreeNode* node : results2)
                results1.push(node);
        }
        return NULL;
    }
};
int main() {
    Solution sol;
    TreeNode* root = new TreeNode(1);
    TreeNode* ans = sol.subtreeWithAllDeepest(root);
    return 0;
}