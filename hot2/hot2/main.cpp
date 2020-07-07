#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};
ListNode* createList(ListNode* list) {
	int num, temp;
	cin >> num;
	cin >> temp;
	ListNode* newNode = new ListNode(temp);
	list = newNode;
	ListNode* tail = list;
	for (int i = 1; i < num; i++) {
		cin >> temp;
		ListNode* newNode = new ListNode(temp);
		tail->next = newNode;
		tail = newNode;
	}
	return list;
}
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* re = NULL;
		int carry = (l1->val + l2->val) > 9 ? 1 : 0, remainder = (l1->val + l2->val) % 10;
		ListNode* newNode = new ListNode(remainder);
		re = newNode;
		ListNode* tail = re;
		ListNode* h1 = l1->next, * h2 = l2->next;
		while (h1 != NULL || h2 != NULL) {
			if (h1 != NULL && h2 != NULL) {
				remainder = (h1->val + h2->val + carry) % 10;
				carry = (h1->val + h2->val + carry) > 9 ? 1 : 0;
				h1 = h1->next;
				h2 = h2->next;
			}
			else if (h1 != NULL) {
				remainder = (h1->val + carry) % 10;
				carry = (h1->val + carry) > 9 ? 1 : 0;
				h1 = h1->next;
			}
			else {
				remainder = (h2->val + carry) % 10;
				carry = (h2->val + carry) > 9 ? 1 : 0;
				h2 = h2->next;
			}
			ListNode* newNode = new ListNode(remainder);
			tail->next = newNode;
			tail = newNode;
		}
		if (carry != 0) {
			ListNode* newNode = new ListNode(carry);
			tail->next = newNode;
			tail = newNode;
		}
		return re;
	}
};
int main() {

	ListNode* l1 = NULL, * l2 = NULL;
	l1=createList(l1);
	l2=createList(l2);
/*	for (ListNode* h = l2; h != NULL; h = h->next)
		cout << h->val << " ";*/
	Solution sol;
	ListNode* result = sol.addTwoNumbers(l1, l2);
	for (ListNode* h = result; h != NULL; h = h->next)
		cout << h->val << " ";
	return 0;
}