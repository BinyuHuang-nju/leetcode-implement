#include <iostream>
using namespace std;
#include <string>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        TreeNode* p = root;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

    }
};