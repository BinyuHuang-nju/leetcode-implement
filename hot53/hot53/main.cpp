#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode dummyHead(0);
        dummyHead.next = head;
        int len = 0;
        ListNode* p = head;
        while (p != NULL) {
            len++;
            p = p->next;
        }
        for (int step = 1; step < len; step = step * 2) {
            ListNode* current = dummyHead.next;
            ListNode* tail = &dummyHead;
            ListNode* left, * right;
            while (current != NULL) {
                left = current;
                right = cut(current, step);
                current = cut(right, step);
                tail->next = merge(left, right);
                while (tail->next)
                    tail = tail->next;
            }
        }
        return dummyHead.next;
    }
private:
    ListNode* cut(ListNode* cur, int step) {
        int time = 0;
        ListNode* p = cur;
        while (time < step - 1 && p != NULL) {
            time++;
            p = p->next;
        }
        if (p == NULL)
            return NULL;

        ListNode* ne = p->next;
        p->next = NULL;
        return ne;
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummyHead(0);
        ListNode* p = &dummyHead;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                p->next = l1;
                p = l1;
                l1 = l1->next;
            }
            else {
                p->next = l2;
                p = l2;
                l2 = l2->next;
            }
        }
        p->next = l1 ? l1 : l2;
        return dummyHead.next;
    }
};