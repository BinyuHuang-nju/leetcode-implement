#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* head = NULL, * tail = NULL;
		ListNode* h1 = l1, * h2 = l2;
		ListNode* temp;
		while (h1 != NULL && h2 != NULL) {
			if (h1->val <= h2->val) {
				temp = h1; 
				h1 = h1->next;
			}
			else {
				temp = h2;
				h2 = h2->next;
			}
			if (head == NULL)
				head = tail = temp;
			else {
				tail->next = temp;
				tail = temp;
			}
		}
		if(h1 != NULL) {
			if (head == NULL)
				head = tail = h1;
			else
				tail->next = h1;
		}
		if (h2 != NULL) {
			if (head == NULL)
				head = tail = h2;
			else
				tail->next = h2;
		}
		return head;
	}
};