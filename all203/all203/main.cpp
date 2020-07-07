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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head)
            return head;
        ListNode* p = head, * pre = NULL;
        while (p != NULL) {
            if (p->val == val) {
                if (p == head) {
                    head = head->next;
                    delete p;
                    p = head;
                }
                else {
                    pre->next = p->next;
                    delete p;
                    p = pre->next;
                }
            }
            else{
                pre = p;
                p = p->next;
            }
        }
        return head;
    }
};