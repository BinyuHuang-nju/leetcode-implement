#include <iostream>
using namespace std;
#include <vector>
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* p = head->next, * pivot;
        head->next = NULL;
        ListNode* pre, * q;
        while (p != NULL) {
            pivot = p;
            p = p->next;
            if (pivot->val <= head->val) {
                pivot->next = head;
                head = pivot;
            }
            else {
                pre = head;
                q = head->next;
                while (q != NULL && pivot->val > q->val) {
                    pre = q;
                    q = q->next;
                }
                if (q == NULL) {
                    pivot->next = NULL;
                    pre->next = pivot;
                }
                else {
                    pre->next = pivot;
                    pivot->next = q;
                }
            }
        }
        return head;
    }
};