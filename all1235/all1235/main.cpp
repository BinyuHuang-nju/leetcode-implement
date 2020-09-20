#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
private:
    struct Job {
        int start;
        int end;
        int profit;
        Job(int s, int e, int p) :start(s), end(e), profit(p) {}
    };
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<Job> jobs;
        int len = startTime.size();
        for (int i = 0; i < len; i++) {
            jobs.push_back(Job(startTime[i], endTime[i], profit[i]));
        }
        sort(jobs.begin(), jobs.end(), [](Job& a, Job& b) {return a.end <= b.end; });
        vector<int> dp(len, 0);
        dp[0] = jobs[0].profit;
        for (int i = 1; i < len; i++) {
            int j = i - 1;
            for (; j >= 0; j--) {
                if (jobs[j].end <= jobs[i].start)
                    break;
            }
            if (j < 0)
                dp[i] = max(dp[i - 1], jobs[i].profit);
            else
                dp[i] = max(dp[i - 1], dp[j] + jobs[i].profit);
        }
        return dp[len - 1];
    }
};
int main() {
    Solution sol;
    vector<int> s = { 1,2,3,4,6 }, e = { 3,5,10,6,9 },p= { 20,20,100,70,60 };
    int re = sol.jobScheduling(s, e, p);
    return 0;
}
/*
    int GetPreJobIdx(vector<Node>& node, int& cur) { // 找到cur之前, node中第一个结束时间>当前开始时间的
        int l = 0;
        int r = cur;
        int mid = 0;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (node[mid].e > node[cur].s) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
    int binarySearch(vector<vector<int>>& cache, int l, int r, int val) {
        //查找第一个终止时间小于等于val的值
        while (l <= r) {
            int mid = (l + r) / 2;
            if (cache[mid][1] > val) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
*/