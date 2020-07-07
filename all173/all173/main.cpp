#include <iostream>
using namespace std;
#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} 
};

class BSTIterator {
private:
    int cur;
    vector<int> inorder;
   
public:
    BSTIterator(TreeNode* root) {
        cur = 0;
        stack<TreeNode*> st;
        TreeNode* p = root;
        while (p != NULL || !st.empty()) {
            if (p != NULL) {
                st.push(p);
                p = p->left;
            }
            else {
                p = st.top();
                st.pop();
                inorder.push_back(p->val);
                p = p->right;
            }
        }
    }

    /** @return the next smallest number */
    int next() {
        int ret = inorder[cur];
        cur++;
        return ret;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (cur < inorder.size());
    }
};