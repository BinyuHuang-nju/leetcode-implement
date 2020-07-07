#include <iostream>
using namespace std;
#include <map>
#include <queue>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root)
            return false;
        map<int, int> val_to_count;
        queue<TreeNode*> que;
        que.push(root);
        TreeNode* p;
        while (!que.empty()) {
            p = que.front();
            que.pop();
            if (!val_to_count.count(p->val))
                val_to_count[p->val] = 1;
            else
                val_to_count[p->val]++;
            if (p->left)
                que.push(p->left);
            if (p->right)
                que.push(p->right);
        }
        map<int, int>::iterator iter;
        for (iter = val_to_count.begin(); iter != val_to_count.end(); iter++) {
            if (iter->first * 2 < k) {
                if (val_to_count.count(k - iter->first))
                    return true;
            }
            else if (iter->first * 2 == k) {
                if (iter->second >= 2)
                    return true;
            }
            else
                break;
        }
        return false;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root)
            return false;
        vector<int> values;
        inorder(root,values);
        int i = 0, j = values.size() - 1;
        while (i < j) {
            if (values[i] + values[j] == k)
                return true;
            else if (values[i] + values[j] < k)
                i++;
            else
                j--;
        }
        return false;
    }
private:

    void inorder(TreeNode* root, vector<int>& vals) {
        if (root) {
            inorder(root->left, vals);
            vals.push_back(root->val);
            inorder(root->right, vals);
        }
    }
};