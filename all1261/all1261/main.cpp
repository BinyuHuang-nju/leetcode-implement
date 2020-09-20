#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <map>

 struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};
class FindElements {
private:
    TreeNode* head;
    map<int, int> mp;
    void changeVal(TreeNode* root, int val) {
        if (!root)
            return;
        root->val = val;
        mp[val] = 1;
        changeVal(root->left, 2 * val + 1);
        changeVal(root->right, 2 * val + 2);
    }
public:
    FindElements(TreeNode* root) {
        head = root;
        changeVal(root, 0);
    }

    bool find(int target) {
        return mp.count(target) > 0;
    }
};
