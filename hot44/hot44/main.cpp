#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	void flatten(TreeNode* root) {
		if (root == NULL)
			return;
		flatten(root->left);
		flatten(root->right);
		if (root->left != NULL) {
			TreeNode* p = root->left, * q = root->right;
			while (p->right != NULL)
				p = p->right;
			root->right = root->left;
			root->left = NULL;
			p->right = q;
		}
	}
};