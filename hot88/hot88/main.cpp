#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution_pass114from126 {
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return 0;
        s = sum;
        return pathSum(root, sum, false)/2;
    }
    int pathSum(TreeNode* root, int sum, bool include_self) {
        if (sum == 0)
            return 1;
        if (root == NULL)
            return 0;
        int include = pathSum(root->left, sum - root->val, true) + pathSum(root->right, sum - root->val, true);
        if (include_self)
            return include;
        return include + pathSum(root->left, s, false) + pathSum(root->right, s, false);
    }
private:
    int s;
};
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return 0;
        s = sum;
        return pathSum_np(root);
    }
    int pathSum_p(TreeNode* root, int sum) {
        if (root == NULL)
            return 0;
        int n = 0;
        if (root->val == sum)
            n = 1;
        n = n + pathSum_p(root->left, sum - root->val) + pathSum_p(root->right, sum - root->val);
        return n;
    }
    int pathSum_np(TreeNode* root) {
        if (root == NULL)
            return 0;
        int n = 0;
        if (root->val == s)
            n = 1;
        n = n + pathSum_np(root->left) + pathSum_np(root->right);
        n = n + pathSum_p(root->left, s - root->val) + pathSum_p(root->right, s - root->val);
        return n;
    }
private:
    int s;
};
int main() {
    return 0;
}