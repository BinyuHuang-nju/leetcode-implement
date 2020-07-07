#include <iostream>
using namespace std;
#include <vector>
#include <map>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};
class Solution {
private:
    int max;
    map<int, int> hashmap;
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        max = 0;
        storeSubtree(root);
        vector<int> results;
        for (map<int, int>::iterator iter = hashmap.begin(); iter != hashmap.end(); iter++) {
            if (iter->second == max)
                results.push_back(iter->first);
        }
        return results;
    }
    int storeSubtree(TreeNode* root) {
        if (!root)
            return 0;
        int num = storeSubtree(root->left) + storeSubtree(root->right) + root->val;
        if (!hashmap.count(num))
            hashmap[num] = 1;
        else
            hashmap[num] += 1;
        if (hashmap[num] > max)
            max = hashmap[num];
        return num;
    }
};