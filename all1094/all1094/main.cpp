#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
class Solution0 {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        if (trips.size() == 0)
            return true;
        int sum = 0;
        for (vector<int> trip : trips) {
            sum += trip[0];
            if (trip[0] > capacity)
                return false;
        }
        if (sum <= capacity)
            return true;
        sort(trips.begin(), trips.end(), [](vector<int>& a, vector<int>& b)
            {return a[1] < b[1] || (a[1] == b[1] && a[2] < b[2]); });
        int max_concurrent = trips[0][0];
        vector<vector<int>> intervals;
        for (vector<int> trip : trips) {
            if (intervals.size() == 0)
                intervals.push_back(trip);
            else if (intervals[intervals.size() - 1][1] == trip[1] && intervals[intervals.size() - 1][2] == trip[2])
                intervals[intervals.size() - 1][0] += trip[0];
            else if (intervals[intervals.size() - 1][2] <= trip[1])
                intervals.push_back(trip);
            else {
                int right;
                if (trip[2] > intervals[intervals.size() - 1][2]) {
                    intervals.push_back({ trip[0],intervals[intervals.size() - 1][2],trip[2] });
                    right = intervals[intervals.size() - 1][2];
                }
                else if (trip[2] < intervals[intervals.size() - 1][2]) {
                    intervals.push_back({ intervals[intervals.size() - 1][0],trip[2],intervals[intervals.size() - 1][2] });
                    right = trip[2];
                }
                for (int i = intervals.size() - 1; i >= 0; i--) {
                    if (trip[1] < intervals[i][1])
                        intervals[i][0] += trip[0];
                    else if(trip[1]){

                    }
                }

            }
        
        }
    }
};

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int start = INT_MAX, end = INT_MIN;
        for (vector<int> trip : trips) {
            start = min(start, trip[1]);
            end = max(end, trip[2]);
        }
        vector<int> passengers(end + 1, 0);
        for (vector<int> trip : trips) {
            passengers[trip[1]] += trip[0];
            passengers[trip[2]] -= trip[0];
        }
        int max_concurrent = 0, cur = 0;
        for (int i = start; i <= end; i++) {
            cur += passengers[i];
            if (max_concurrent < cur) {
                max_concurrent = cur;
                if (max_concurrent > capacity)
                    return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (vector<int> trip : trips) {
            pq.push(make_pair(trip[1], trip[0]));
            pq.push(make_pair(trip[2], -trip[0]));
        }
        int cur = 0;
        while (!pq.empty()) {
            int p = pq.top().second;
            pq.pop();
            cur += p;
            if (cur > capacity)
                return false;
        }
        return true;
    }
};

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](vector<int>& a, vector<int>& b) {return a[1] < b[1] || (a[1] == b[1] && a[2] < b[2]); });
        stack<vector<int>> st;
        for (vector<int> trip : trips) {
            if (st.empty() || st.top()[2] <= trip[1])
                st.push(trip);
            else if (st.top()[1] == trip[1] && st.top()[2] == trip[2])
                st.top()[0] += trip[0];
            else {
                int left = trip[1], right = trip[2];

            }
        }
    }
};


int main() {
    Solution sol;
    vector<vector<int>> a = { {7,5,6},{6,7,8},{10,1,6} };
    sol.carPooling(a, 16);
    return 0;
}