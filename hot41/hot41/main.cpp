#include <iostream>
using namespace std;
#include <vector>
#include <queue>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (root == NULL)
			return res;
		vector<int> cur;
		queue<TreeNode*> q;
		TreeNode* flag = new TreeNode(INT_MIN);
		TreeNode* p;
		q.push(root);
		q.push(flag);
		while (!q.empty()) {
			p = q.front();
			q.pop();
			if (p->left != NULL)
				q.push(p->left);
			if (p->right != NULL)
				q.push(p->right);
			cur.push_back(p->val);
			if (!q.empty() && q.front() == flag) {
				res.push_back(cur);
				cur.clear();
				q.pop();
				q.push(flag);
			}
		}
		return res;
	}
};