#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        bool done = false, doing = false;
        vector<int> temp(2, 0);
        for (int i = 0; i < intervals.size(); i++) {
            if (done)
                res.push_back(intervals[i]);
            else{
                if (!doing) {
                    if (newInterval[0] <= intervals[i][1]) {
                        doing = true;
                        if (newInterval[0] <= intervals[i][0])
                            temp[0] = newInterval[0];
                        else
                            temp[0] = intervals[i][0];
                    }
                    else {
                        res.push_back(intervals[i]);
                    }
                }
                if (doing) {
                    if (newInterval[1] <= intervals[i][1]) {
                        if (newInterval[1] < intervals[i][0]) {
                            temp[1] = newInterval[1];
                            res.push_back(temp);
                            res.push_back(intervals[i]);
                            done = true;
                        }
                        else {
                            temp[1] = intervals[i][1];
                            res.push_back(temp);
                            done = true;
                        }
                    }
                }
            }
        }
        if (!doing)
            res.push_back(newInterval);
        else if (!done) {
            temp[1] = newInterval[1];
            res.push_back(temp);
        }
        return res;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> a = { {1,2},{3,5},{6,7},{8,10},{12,16} };
    vector<int> b = { 4,8 };
    vector<vector<int>> c = sol.insert(a, b);
    return 0;
}