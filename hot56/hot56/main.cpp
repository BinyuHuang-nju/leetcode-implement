#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == NULL || headB == NULL)
            return NULL;
        int len1 = 0, len2 = 0;
        ListNode* p1 = headA, * p2 = headB;
        for (; p1 != NULL; p1 = p1->next)
            len1++;
        for (; p2 != NULL; p2 = p2->next)
            len2++;
        int diff;
        if (len1 > len2) {
            diff = len1 - len2;
            p1 = headA;
            p2 = headB;
        }
        else {
            diff = len2 - len1;
            p1 = headB;
            p2 = headA;
        }
        if (diff > 0)
            for (int i = 0; i < diff; i++)
                p1 = p1->next;
        for (; p1 != NULL; p1 = p1->next, p2 = p2->next) {
            if (p1 == p2)
                return p1;
        }
        return NULL;
    }
};