#include <iostream>
using namespace std;
#include<vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int distributeCoins(TreeNode* root) {
        if (!root)
            return 0;
        int moveTimes = 0;
        moveCoins(root, moveTimes);
        return moveTimes;
    }
    int moveCoins(TreeNode* root, int& times) {
        if (!root)
            return 0;
        if (!root->left && !root->right) {
            if (root->val == 0) {
                times++;
                return -1;
            }
            else if (root->val == 1)
                return 0;
            else {
                times += (root->val - 1);
                return (root->val - 1);
            }
        }
        int l = moveCoins(root->left, times), r = moveCoins(root->right, times);
        int moves = l + r + root->val - 1;
        if (moves < 0) {
            times += (-moves);
            return moves;
        }
        else if (moves == 0)
            return 0;
        else {
            times += moves;
            return moves;
        }
        return 0;
    }
};
int main() {
    Solution sol;
    TreeNode* p1 = new TreeNode(4);
    TreeNode* p2 = new TreeNode(0);
    TreeNode* p3 = new TreeNode(0);
    TreeNode* p4 = new TreeNode(0);
    p1->left = p2;
    p2->right = p3;
    p3->right = p4;
    int x = sol.distributeCoins(p1);
    return 0;
}