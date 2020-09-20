#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        if (!root)
            return 0;
        vector<int> cnt(distance, 0);
        return subPairs(root, distance, cnt);
    }
    int subPairs(TreeNode* root, int distance, vector<int>& cnt) {
        if (!root->left && !root->right) {
            cnt[0] = 1;
            return 0;
        }
        else if (!root->right) {
            int result = subPairs(root->left, distance, cnt);
            for (int i = distance - 1; i > 0; i--)
                cnt[i] = cnt[i - 1];
            cnt[0] = 0;
            return result;
        }
        else if (!root->left) {
            int result = subPairs(root->right, distance, cnt);
            for (int i = distance - 1; i > 0; i--)
                cnt[i] = cnt[i - 1];
            cnt[0] = 0;
            return result;
        }
        vector<int> tmp1(distance, 0), tmp2(distance, 0);
        int result = subPairs(root->left, distance, tmp1) + subPairs(root->right, distance, tmp2);
        for (int i = distance - 1; i > 0; i--) {
            tmp1[i] = tmp1[i - 1];
            tmp2[i] = tmp2[i - 1];
        }
        tmp1[0] = tmp2[0] = 0;
        for (int i = 1; i < distance; i++) {
            if (tmp1[i] == 0)
                continue;
            for (int j = 1; i + j <= distance; j++) {
                result += tmp1[i] * tmp2[j];
            }
        }
        for (int i = 0; i < distance; i++)
            cnt[i] = tmp1[i] + tmp2[i];
        return result;
    }
};
int main() {
    Solution sol;
    TreeNode* p1 = new TreeNode(1);
    TreeNode* p2 = new TreeNode(1);
    TreeNode* p3 = new TreeNode(1);
    p1->left = p2;
    p1->right = p3;
    int x= sol.countPairs(p1, 3);
    return 0;
}