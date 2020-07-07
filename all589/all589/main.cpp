#include <iostream>
using namespace std;
#include <vector>
#include <stack>

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution1 {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if (!root)
            return res;
        preorder(root, res);
        return res;
    }
    void preorder(Node* root, vector<int>& res) {
        res.push_back(root->val);
        for (int i = 0; i < root->children.size(); i++) {
            preorder(root->children[i], res);
        }
    }
};

class Solution2 {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if (!root)
            return res;
        stack<Node*> st;
        Node* p = root;
        while (p != NULL) {
            res.push_back(p->val);
            int num = p->children.size();
            if (num > 0) {
                for (int i = num - 1; i > 0; i--)
                    st.push(p->children[i]);
                p = p->children[0];
            }
            else {
                if (!st.empty()) {
                    p = st.top();
                    st.pop();
                }
                else
                    p = NULL;
            }
        }
        return res;
    }

};