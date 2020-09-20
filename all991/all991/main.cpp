#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class Solution1 {   // true but exceeds time limitations.
public:
    int brokenCalc(int X, int Y) {
        if (X >= Y)
            return (X - Y);
        int distance = 0, v;
        queue<int> que;
        que.push(X);
        que.push(-1);
        while (!que.empty()) {
            v = que.front();
            que.pop();
            if (v == Y)
                return distance;
            que.push(2 * v);
            if (v > 1)
                que.push(v - 1);
            if (!que.empty() && que.front() == -1) {
                que.pop();
                distance++;
                que.push(-1);
            }
        }
        return INT_MAX;
    }
};

class Solution {
public:
    int brokenCalc(int X, int Y) {
        if (X >= Y)
            return (X - Y);
        int times = 0;
        while (X < Y) {
            if (Y % 2 != 0)
                Y++;
            else {
                Y = Y / 2;
            }
            times++;
        }
        return times + X - Y;
    }
};
