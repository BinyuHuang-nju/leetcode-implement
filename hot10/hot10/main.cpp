#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};
ListNode* createList(ListNode* list,int num) {
	int temp;
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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int i;
		bool athead = false;
		ListNode* p1 = head, * p2pre = head;
		for (i = 0; i < n + 1; i++) {
			if (p1 != NULL)
				p1 = p1->next;
			else {
				athead = true;
				break;
			}
		}
		if (athead == false)
		{
			while (p1 != NULL) {
				p1 = p1->next;
				p2pre = p2pre->next;
			}
			ListNode* q = p2pre->next;
			p2pre->next = q->next;
			delete q;
		}
		else {
			ListNode* q = head;
			head = head->next;
			delete q;
		}
		return head;
	}
};
int main() {
	int num;
	cin >> num;
	ListNode* l = NULL;
	l = createList(l, num);
	Solution sol;
	int n;
	cin >> n;
	ListNode* result = sol.removeNthFromEnd(l, n);
	for (ListNode* h = result; h != NULL; h = h->next)
		cout << h->val << " ";
	return 0;
}