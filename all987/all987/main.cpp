#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> results;
        if (!root)
            return results;
        vector<vector<int>> temps;
        queue<TreeNode*> queNode;
        TreeNode* tag = new TreeNode(-1);
        queNode.push(root);
        queNode.push(tag);
        TreeNode* p;
        vector<int> NumSame;
        while (!queNode.empty()) {
            p = queNode.front();
            queNode.pop();

        }

        int begin = temps.size();
        if (begin) {
            if (begin % 2 == 0)
                begin--;
            else
                begin -= 2;
        }
        for (int i = begin; i > 0; i = i - 2) {
            if(temps[i].size())
                results.push_back(temps[i]);
        }
        for (int i = 0; i < temps.size(); i = i + 2) {
            if(temps[i].size())
                results.push_back(temps[i]);
        }
        return results;
    }
    void storeVal(TreeNode* root, int location, int depth,vector<vector<int>>& temps) {
        if (!root)
            return;
        int index = 0;
        if (location < 0)
            index = -2 * location - 1;
        else
            index = 2 * location;
        if (index >= temps.size()) {
            for (int i = temps.size(); i <= index; i++)
                temps.push_back({});
        }
        if (temps[index].size() == 0)
            temps[index].push_back(root->val);
        else {
            int i;
            for (i = temps[index].size() - 1; i >= 0; i--) {
                if (root->val > temps[index][i]) {
                    temps[index].insert(temps[index].begin() + i + 1, root->val);
                    break;
                }
            }
            if (i < 0)
                temps[index].insert(temps[index].begin(), root->val);
        }
        storeVal(root->left, location - 1,depth+1, temps);
        storeVal(root->right, location + 1, depth+1,temps);
    }
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> results;
        vector<vector<int>> temps;
        storeVal(root, 0, 0, temps);
        int begin = temps.size();
        for (int i = 0; i < begin; i++) {
            if (temps[i].size()) {
                for (int j = 0; j < temps[i].size(); j++)
                    temps[i][j] = temps[i][j] % 1000;
            }
        }
        if (begin) {
            if (begin % 2 == 0)
                begin--;
            else
                begin -= 2;
        }
        for (int i = begin; i > 0; i = i - 2) {
            if (temps[i].size())
                results.push_back(temps[i]);
        }
        for (int i = 0; i < temps.size(); i = i + 2) {
            if (temps[i].size())
                results.push_back(temps[i]);
        }
        return results;
    }
    void storeVal(TreeNode* root, int location, int depth, vector<vector<int>>& temps) {
        if (!root)
            return;
        int index = 0;
        if (location < 0)
            index = -2 * location - 1;
        else
            index = 2 * location;
        if (index >= temps.size()) {
            for (int i = temps.size(); i <= index; i++)
                temps.push_back({});
        }
        int k = depth * 1000 + root->val;
        if (temps[index].size() == 0)
            temps[index].push_back(k);
        else {
            int i;
            for (i = temps[index].size() - 1; i >= 0; i--) {
                if (k > temps[index][i]) {
                    temps[index].insert(temps[index].begin() + i + 1, k);
                    break;
                }
            }
            if (i < 0)
                temps[index].insert(temps[index].begin(), k);
        }
        storeVal(root->left, location - 1, depth + 1, temps);
        storeVal(root->right, location + 1, depth + 1, temps);
    }
};