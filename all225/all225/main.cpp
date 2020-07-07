#include <iostream>
using namespace std;
#include <queue>
class MyStack {
private:
    queue<int> que;
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        int size = que.size();
        que.push(x);
        int temp;
        while (size > 0) {
            temp = que.front();
            que.pop();
            que.push(temp);
            size--;
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res = que.front();
        que.pop();
        return res;
    }

    /** Get the top element. */
    int top() {
        return que.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }
};
