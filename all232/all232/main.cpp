#include <iostream>
using namespace std;
#include <stack>

class MyQueue {
private:
    stack<int> st1;
    stack<int> st2;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        st1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int ret;
        if (!st2.empty()) {
            ret = st2.top();
            st2.pop();
            return ret;
        }
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        ret = st2.top();
        st2.pop();
        return ret;
    }

    /** Get the front element. */
    int peek() {
        if (!st2.empty()) {
            return st2.top();
        }
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        return st2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return (st1.empty() && st2.empty());
    }
};