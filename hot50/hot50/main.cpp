#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == NULL)
            return false;
        ListNode* fast = head->next, * slow = head;
        while (fast != NULL) {
            if (fast == slow)
                return true;
            fast = fast->next;
            if (fast == slow)
                return true;
            if (fast != NULL)
                fast = fast->next;
            slow = slow->next;
        }
        return false;
    }
};