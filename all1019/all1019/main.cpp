#include <iostream>
using namespace std;
#include <vector>
#include <stack>
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        if (!head)
            return {};
        stack<int> state, results;
        dfs(head, state, results);
        vector<int> ret;
        while (!results.empty()) {
            ret.push_back(results.top());
            results.pop();
        }
        return ret;
    }
    void dfs(ListNode* head, stack<int>& state, stack<int>& results) {
        if (head->next)
            dfs(head->next, state, results);

        while (!state.empty() && state.top() <= head->val)
            state.pop();
        if (state.empty()) {
            results.push(0);
        }
        else {
            results.push(state.top());
        }
        state.push(head->val);
    }
};