#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <queue>

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        if (barcodes.size() < 3)
            return barcodes;
        map<int, int> mp;
        for (int barcode : barcodes) {
            if (!mp.count(barcode))
                mp[barcode] = 1;
            else
                mp[barcode]++;
        }
        priority_queue<pair<int, int>> heap;
        for (map<int, int>::iterator iter = mp.begin(); iter != mp.end(); iter++)
            heap.push(make_pair(iter->second, iter->first));
        vector<int> results;
        while (heap.size() > 1) {
            pair<int, int> p1 = heap.top();
            heap.pop();
            pair<int, int> p2 = heap.top();
            heap.pop();
            results.push_back(p1.second);
            results.push_back(p2.second);
            p1.first--;
            p2.first--;
            if (p1.first > 0)
                heap.push(p1);
            if (p2.first > 0)
                heap.push(p2);
        }
        if (!heap.empty())
            results.push_back(heap.top().second);
        return results;
    }
};