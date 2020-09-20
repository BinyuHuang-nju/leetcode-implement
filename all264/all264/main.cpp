#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
class Solution1 {
public:
    int nthUglyNumber(int n) {
        if (n < 2)
            return n;
        int inc[3] = { 2,3,5 };
        map<int, int> visited;
        int cur = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(1);
        visited[1] = 1;
        int top;
        while (!pq.empty()&&cur<n) {
            top = pq.top();
            pq.pop();
            cur++;
            for (int i = 0; i < 3; i++) {
                long long tmp = (long long)inc[i] * top;
                if (tmp > (long long)INT_MAX)
                    continue;
                if (!visited.count(tmp)) {
                    pq.push(tmp);
                    visited[tmp] = 1;
                }
            }
        }
        return top;
    }
};
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n < 2)
            return n;
        int p2 = 0, p3 = 0, p5 = 0;
        vector<int> num(n, 0);
        num[0] = 1;
        for (int i = 1; i < n; i++) {
            num[i] = min(min(num[p2] * 2, num[p3] * 3), num[p5] * 5);
            if (num[i] == num[p2] * 2)
                p2++;
            if (num[i] == num[p3] * 3)
                p3++;
            if (num[i] == num[p5] * 5)
                p5++;
        }
        return num[n - 1];
    }
};
int main() {
    Solution sol;
    sol.nthUglyNumber(10);
    return 0;
}