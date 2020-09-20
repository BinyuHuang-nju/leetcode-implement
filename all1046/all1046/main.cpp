#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int>> heap;
        for (int stone : stones)
            heap.push(stone);
        while (heap.size() > 1) {
            int big1 = heap.top();
            heap.pop();
            int big2 = heap.top();
            heap.pop();
            if (big1 > big2)
                heap.push(big1 - big2);
        }
        if (heap.empty())
            return 0;
        return heap.top();
    }
};