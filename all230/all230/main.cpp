#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <stack>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {

public:
    int kthSmallest(TreeNode* root, int k) {
        //map<TreeNode*, int> order;
        stack<TreeNode*> st;
        TreeNode* p = root;
        int cur = 1;
        while (p != NULL || !st.empty()) {
            if (p != NULL) {
                st.push(p);
                p = p->left;
            }
            else {
                p = st.top();
                st.pop();
                //order[p] = cur;
                if (cur == k)
                    return p->val;
                cur++;
                p = p->right;
            }
        }
        return 0;
    }

};

class Solution2 {
private:
    map<TreeNode*, int> childnum;
public:
    int kthSmallest(TreeNode* root, int k) {
        int before = Leftnum(root);
        if (k == before + 1)
            return root->val;
        else if (k < before + 1) {
            return kthSmallest(root->left, k);
        }
        return kthSmallest(root->right, k - before - 1);
    }
    int Leftnum(TreeNode* root) {
        if (!root || !root->left)
            return 0;
        return 1 + Childnum(root->left);
    }
    int Childnum(TreeNode* root) {
        if (childnum.count(root))
            return childnum[root];
        int res = 0;
        if (root->left)
            res += 1 + Childnum(root->left);
        if (root->right)
            res += 1 + Childnum(root->right);
        childnum[root] = res;
        return res;
    }

};