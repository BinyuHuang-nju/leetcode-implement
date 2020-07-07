#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return NULL;
        if (head->next == head)
            return head;
        ListNode* fast = head, * slow = head;
        bool hasCycle = false;
        while (fast->next != NULL && slow->next != NULL) {
            fast = fast->next;
            if (fast->next)
                fast = fast->next;
            else
                return NULL;
            slow = slow->next;
            if (fast == slow) {
                hasCycle = true;
                break;
            }
        }
        if (!hasCycle)
            return NULL;
        //slow = slow->next;
        ListNode* slow2 = head;
        while (slow != slow2) {
            slow = slow->next;
            slow2 = slow2->next;
        }
        return slow;
    }
};