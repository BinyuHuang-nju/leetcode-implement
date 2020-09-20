#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> mp;
        for (int a : arr) {
            if (!mp.count(a))
                mp[a] = 1;
            else
                mp[a]++;
        }
        priority_queue<int, vector<int>, less<int>> que;
        for (map<int, int>::iterator iter = mp.begin(); iter != mp.end(); iter++)
            que.push(iter->second);
        int goal = arr.size() / 2, cur = 0;
        int elems = 0;
        while (!que.empty()) {
            cur += que.top();
            elems++;
            que.pop();
            if (cur >= goal)
                break;
        }
        return elems;
    }
};
int main() {
    Solution sol;
    vector<int> a = { 3,3,3,3,5,5,5,2,2,7 };
    sol.minSetSize(a);
    return 0;
}