#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> cnt;
        for (int element : arr) {
            if (!cnt.count(element))
                cnt[element] = 1;
            else
                cnt[element]++;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        int nums = 0;
        for (auto pointer : cnt) {
            nums++;
            pq.push(pointer.second);
        }
        while (k > 0 && !pq.empty()) {
            int x = pq.top();
            pq.pop();
            if (k >= x) {
                k = k - x;
                nums--;
            }
            else {
                k = 0;
            }
        }
        return nums;
    }
};
int main() {
    Solution sol;
    vector<int> a = { 4,3,1,1,3,3,2 };
    sol.findLeastNumOfUniqueInts(a, 3);
    return 0;
}