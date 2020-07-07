#include <iostream>
using namespace std;
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        queue<Node*> queNode;
        Node* tag = new Node(0);
        queNode.push(root);
        queNode.push(tag);
        Node* p;
        int i;
        vector<int> cur;
        while (!queNode.empty()) {
            p = queNode.front();
            queNode.pop();
            cur.push_back(p->val);
            for (i = 0; i < p->children.size(); i++)
                queNode.push(p->children[i]);
            if (!queNode.empty() && queNode.front() == tag) {
                queNode.pop();
                res.push_back(cur);
                cur.clear();
                if (!queNode.empty())
                    queNode.push(tag);
            }
        }
        return res;
    }
};
class Solution2 {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        queue<Node*> queNode;
        queNode.push(root);
        int num = 1;
        Node* p;
        int i;
        vector<int> cur;
        while (!queNode.empty()) {
            num = queNode.size();
            while (num) {
                p = queNode.front();
                queNode.pop();
                cur.push_back(p->val);
                for (i = 0; i < p->children.size(); i++)
                    queNode.push(p->children[i]);
                num--;
            }
            res.push_back(cur);
            cur.clear();
        }
        return res;
    }
};