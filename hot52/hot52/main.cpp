#include <iostream>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        maxsize = capacity;
        current = 0;
        head = tail = NULL;
    }

    int get(int key) {
        if (current == 0)
            return -1;
        if (head->key == key)
            return head->value;
        ListNode* p = head->next;
        for (; p != head; p = p->next) {
            if (p->key == key) {
                if (p == tail) {
                    head = tail;
                    tail = tail->pre;
                }
                else {
                    p->pre->next = p->next;
                    p->next->pre = p->pre;
                    head->pre = p;
                    tail->next = p;
                    p->pre = tail;
                    p->next = head;
                    head = p;
                }
                return p->value;
            }
        }
        return -1;
    }

    void put(int key, int value) {
        if (current == 0) {
            ListNode* newNode = new ListNode(key, value);
            head = tail = newNode;
            head->next = head;
            head->pre = head;
            current++;
            return;
        }
        if (head->key == key) {
            head->value = value;
            return;
        }
        else {
            ListNode* p = head->next;
            for (; p != head; p = p->next) {
                if (p->key == key) {
                    p->value = value;
                    if (p == tail) {
                        head = tail;
                        tail = tail->pre;
                    }
                    else {
                        p->pre->next = p->next;
                        p->next->pre = p->pre;
                        head->pre = p;
                        tail->next = p;
                        p->pre = tail;
                        p->next = head;
                        head = p;
                    }
                    return;
                }
            }
        }
        if (current < maxsize) {
            ListNode* newNode = new ListNode(key, value);
            newNode->next = head;
            newNode->pre = tail;
            head->pre = newNode;
            tail->next = newNode;
            head = newNode;
            current++;
        }
        else {
            ListNode* newNode = new ListNode(key, value);
            ListNode* q = tail;
            if (maxsize == 1) {
                delete q;
                head = tail = newNode;
                head->next = head;
                head->pre = head;
            }
            else {
                tail = tail->pre;
                delete q;
                newNode->next = head;
                newNode->pre = tail;
                head->pre = newNode;
                tail->next = newNode;
                head = newNode;
            }
        }
    }
private:
    int current;
    int maxsize;
    struct ListNode {
        int key;
        int value;
        ListNode* pre;
        ListNode* next;
        ListNode(int x, int y) :key(x), value(y), pre(NULL), next(NULL) {}
    };
    ListNode* head, * tail;
};
int main() {
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);       // 返回  1
    cache.put(3, 3);    // 该操作会使得密钥 2 作废
    cache.get(2);       // 返回 -1 (未找到)
    cache.put(4, 4);    // 该操作会使得密钥 1 作废
    cache.get(1);       // 返回 -1 (未找到)
    cache.get(3);       // 返回  3
    cache.get(4);       // 返回  4
}