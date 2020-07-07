#include <iostream>
using namespace std;
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return NULL;
        TreeNode* p = root, * parent = NULL;
        bool isLeft = true;
        while (p != NULL) {
            if (p->val == key) {
                break;
            }
            else if (p->val < key) {
                parent = p;
                p = p->right;
                isLeft = false;
            }
            else {
                parent = p;
                p = p->left;
                isLeft = true;
            }
        }
        if (!p)
            return root;
        if (!p->left && !p->right) {
            if (!parent) {
                delete p;
                return NULL;
            }
            else {
                delete p;
                if (isLeft) {
                    parent->left = NULL;
                }
                else
                    parent->right = NULL;
            }
        }
        else if (!p->right) {
            if (!parent) {
                root = p->left;
                delete p;
                return root;
            }
            if (isLeft)
                parent->left = p->left;
            else
                parent->right = p->left;
            delete p;
        }
        else if (!p->left) {
            if (!parent) {
                root = p->right;
                delete p;
                return root;
            }
            if (isLeft)
                parent->left = p->right;
            else
                parent->right = p->right;
            delete p;
        }
        else {
            TreeNode* ex = p->right;
            if (!ex->left) {
                ex->left = p->left;
                if (!parent) {
                    root = ex;
                    delete p;
                    return root;
                }
                if (isLeft)
                    parent->left = ex;
                else
                    parent->right = ex;
                delete p;
            }
            else {
                while (ex->left->left != NULL)
                    ex = ex->left;
                TreeNode* ex1 = ex->left;
                ex->left = ex1->right;
                ex1->left = p->left;
                ex1->right = p->right;
                if (!parent) {
                    root = ex1;
                    delete p;
                    return root;
                }
                if (isLeft)
                    parent->left = ex1;
                else
                    parent->right = ex1;
                delete p;
            }
        }
        return root;
    }
};