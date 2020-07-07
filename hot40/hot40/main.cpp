#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
			return true;
		if (root->left == NULL && root->right == NULL)
			return true;
		if (root->left != NULL && root->right != NULL)
			return (root->left->val == root->right->val) & symmetric(root->left, root->right);
		return false;
	}
private:
	bool symmetric(TreeNode* p1, TreeNode* p2) {
		if (!p1->left && !p1->right && !p2->left && !p2->right)
			return true;
		bool res = true;
		if (p1->left != NULL && p2->right != NULL)
			res = res & (p1->left->val == p2->right->val) & symmetric(p1->left, p2->right);
		if (p1->right != NULL && p2->left != NULL)
			res = res & (p1->right->val == p2->left->val) & symmetric(p1->right, p2->left);
		if((p1->left&&!p2->right)||(p1->right&&!p2->left)||(!p1->left&&p2->right)||(!p1->right&&p2->left))
			return false;
		return res;
	}
};