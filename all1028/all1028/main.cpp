#include <iostream>
using namespace std;
#include <cstring>
#include <string>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        if (S.length() == 0)
            return NULL;
        return createTree(S, 0);
    }
    TreeNode* createTree(string str, int depth) {
        if (str.length() == 0)
            return NULL;
        int i = 1;
        while (i < str.length() && str[i] != '-')
            i++;
        TreeNode* root = new TreeNode(str_to_integer(str.substr(0, i)));
        if (i == str.length())
            return root;
        int j = i + depth + 2, num = 0;
        while (j < str.length()) {
            if (str[j] != '-') {
                if (num == depth + 1)
                    break;
                num = 0;
            }
            else {
                num++;
            }
            j++;
        }
        if (j == str.length()) {
            root->left = createTree(str.substr(i + depth + 1), depth + 1);
            return root;
        }
        root->left = createTree(str.substr(i + depth + 1, j - i - 2 * depth - 2), depth + 1);
        root->right = createTree(str.substr(j), depth + 1);
        return root;
    }
    int str_to_integer(string str) {
        int res = 0;
        for (int i = 0; i < str.length(); i++) {
            res = res * 10 + (str[i] - '0');
        }
        return res;
    }
};
int main() {
    Solution sol;
    string s = "1-2--3--4-5--6--7";
    TreeNode* t =sol.recoverFromPreorder(s);
    return 0;
}