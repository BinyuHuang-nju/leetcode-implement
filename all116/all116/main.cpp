#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return NULL;
        queue<Node*> que;
        Node* tag = new Node(-1);
        root->next = NULL;
        que.push(root);
        que.push(tag);
        Node* p;
        while (!que.empty()) {
            p = que.front();
            que.pop();
            if (p->left)
                que.push(p->left);
            if (p->right)
                que.push(p->right);
            if (!que.empty() && que.front() != tag)
                p->next = que.front();
            else if (!que.empty() && que.front() == tag) {
                p->next = NULL;
                que.pop();
                if (!que.empty())
                    que.push(tag);
            }
        }
        return root;
    }
};