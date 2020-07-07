#include <iostream>
using namespace std;
class MinStack {
public:
    MinStack() {
        min = currentSize = 0;
        head = tail = NULL;
    }

    void push(int x) {
        ListNode* p = new ListNode(x);
        if (currentSize == 0) {
            head = tail = p;
            min = x;
        }
        else {
            tail->next = p;
            p->pre = tail;
            tail = p;
            if (x < min)
                min = x;
        }
        currentSize++;
    }

    void pop() {
        currentSize--;
        if (currentSize == 0) {
            ListNode* q = tail;
            delete q;
            head = tail = NULL;
        }
        else {
            ListNode* q = tail;
            tail = tail->pre;
            tail->next = NULL;
            if (q->val == min) {
                min = head->val;
                ListNode* p = head->next;
                for (; p != NULL; p = p->next)
                    if (p->val < min)
                        min = p->val;
            }
            delete q;
        }
    }

    int top() {
        if (tail)
            return tail->val;
        return 0;
    }

    int getMin() {
        return min;
    }
private:
    struct ListNode {
        int val;
        ListNode* pre;
        ListNode* next;
        ListNode(int x) :val(x), pre(NULL), next(NULL) {}
    };
    ListNode* head, * tail;
    int min; //每次入两个元素(元素+当前min) or stack+minstack
    int currentSize;
};