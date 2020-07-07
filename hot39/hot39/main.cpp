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
	bool isValidBST(TreeNode* root) {
		if (root == NULL)
			return true;
		bool res = isValidBST(root->left) & isValidBST(root->right);
		TreeNode* p;
		if (root->left != NULL) {
			p = root->left;
			while (p->right != NULL)
				p = p->right;
			res = res & (p->val < root->val);
		}
		if (root->right != NULL) {
			p = root->right;
			while (p->left != NULL)
				p = p->left;
			res = res & (p->val > root->val);
		}
		return res;
	}
};
int main() {
	Solution sol;
	TreeNode* p = new TreeNode(10);
	p->left = new TreeNode(5);
	return 0;
}