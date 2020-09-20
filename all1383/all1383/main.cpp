#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <queue>
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        const int M = 1e9 + 7;
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<pair<int, int>> data;
        for (int i = 0; i < n; i++)
            data.push_back(make_pair(speed[i], efficiency[i]));
        sort(data.begin(), data.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if (a.second != b.second) return a.second > b.second;
            return a.first > b.first;
            });
        pq.push(data[0].first);
        int numpq = 1, curEfficiency = data[0].second;
        long long totalspeeds = data[0].first;
        long long result = (long long)data[0].first * data[0].second;
        for (int i = 1; i < n; i++) {
            if (numpq < k) {
                pq.push(data[i].first);
                numpq++;
                totalspeeds += data[i].first;
            }
            else if (data[i].first > pq.top()) {
                totalspeeds += ((long long)data[i].first - pq.top());
                pq.pop();
                pq.push(data[i].first);
            }
            else
                continue;
            curEfficiency = data[i].second;
            result = max(result, totalspeeds * curEfficiency);
        }
        return (int)(result % M);
    }
};
int main() {
    Solution sol;
    vector<int> speed = { 2,10,3,1,5,8 }, efficiency = { 5,4,3,9,7,2 };
    sol.maxPerformance(6,speed, efficiency, 4);
    return 0;
}