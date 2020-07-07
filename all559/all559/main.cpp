#include <iostream>
using namespace std;
#include <vector>
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
class Solution {
public:
    int maxDepth(Node* root) {
        if (!root)
            return 0;
        if (root->children.size() == 0)
            return 1;
        int max = 0, cur;
        for (int i = 0; i < root->children.size(); i++) {
            cur = maxDepth(root->children[i]);
            if (max < cur)
                max = cur;
        }
        return (max + 1);
    }
};
int main() {
    Solution sol;
    Node* p5 = new Node(5);
    Node* p6 = new Node(6);
    Node* p2 = new Node(2);
    Node* p4 = new Node(4);
    Node* p3 = new Node(3);
    p3->children.push_back(p5);
    p3->children.push_back(p6);
    Node* p1 = new Node(1);
    p1->children.push_back(p3);
    p1->children.push_back(p2);
    p1->children.push_back(p4);
    cout << sol.maxDepth(p1);
    return 0;
}