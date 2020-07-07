#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}  
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;
        int len = 0, i;
        ListNode* p;
        for (p = head; p != NULL; p = p->next)
            len++;
        p = head;
        for (i = 0; i < len / 2 - 1; i++)
            p = p->next;
        ListNode* head1 = head, * tail1 = p;
        //tail1->next = NULL;
        if (len % 2 != 0)
            p = p->next;
        p = p->next;
        ListNode* head2 = p;
        ListNode* tail2 = head2;
        ListNode* prev = NULL, * ovn = NULL;
        while (tail2 != NULL) {
            ovn = tail2->next;
            tail2->next = prev;
            prev = tail2;
            tail2 = ovn;
        }
        ListNode* p1 = head1, * p2 = prev;
        for (i = 0; i < len / 2; i++) {
            if (p1->val != p2->val)
                return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};
int main() {
/*    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(3);
    ListNode* p3 = new ListNode(2);
    ListNode* p4 = new ListNode(4);
    ListNode* p5 = new ListNode(3);
    ListNode* p6 = new ListNode(2);
    ListNode* p7 = new ListNode(1);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;
    p6->next = p7;*/
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(2);
    ListNode* p3 = new ListNode(2);
    ListNode* p4 = new ListNode(1);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    Solution sol;
    cout << sol.isPalindrome(p1);
    return 0;
}