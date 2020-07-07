#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.size() == 0)
            return res;
        quicksort(intervals, 0, intervals.size() - 1);
        res.push_back(intervals[0]);
        int cur, i;
        for (i = 1; i < intervals.size(); i++) {
            cur = res.size() - 1;
            if (intervals[i][0] > res[cur][1])
                res.push_back(intervals[i]);
            else {
                if (intervals[i][1] > res[cur][1])
                    res[cur][1] = intervals[i][1];
            }
        }
        return res;
    }
private:

    void quicksort(vector<vector<int>>& a, int begin, int end) {
        if (begin < end) {
            int pivot = partition(a, begin, end);
            quicksort(a, begin, pivot - 1);
            quicksort(a, pivot + 1, end);
        }
    }
    int partition(vector<vector<int>>& a, int begin, int end) {
        vector<int> pivot(a[end]);
        vector<int> temp;
        int i = begin;
        for(int j=begin;j<end;j++)
            if (a[j][0] < pivot[0]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                i++;
            }
        temp = a[i];
        a[i] = a[end];
        a[end] = temp;
        return i;
    }
};
int main() {
    vector<vector<int>> intervals = { {1,3},{2,6},{8,10},{15,18} };
    Solution sol;
    vector<vector<int>> re = sol.merge(intervals);
    return 0;
}