#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <cstring>

class Solution1 {
public:
    vector<string> readBinaryWatch(int num) {
        vector<int> hour = { 0,1,1,2,1,2,2,3,1,2,2,3 };
        vector<int> minute(60, 0);
        int pow = 2;
        minute[0] = 0;
        minute[1] = 1;
        for (int i = 2; i < 60; i++) {
            if (i == pow * 2)
                pow = i;
            minute[i] = minute[i - pow] + 1;
        }
        vector<string> res;
        vector<int> s1, s2;
        int start = num < 6 ? 0 : (num - 5);
        int end = num > 3 ? 3 : num;
        int i, j, m, n;
        for (i = start; i <= end; i++) {
            j = num - i;
            s1.clear();
            s2.clear();
            for (m = 0; m < 12; m++)
                if (hour[m] == i)
                    s1.push_back(m);
            for (n = 0; n < 60; n++)
                if (minute[n] == j)
                    s2.push_back(n);
            for (m = 0; m < s1.size(); m++) {
                for (n = 0; n < s2.size(); n++) {
                    if (s2[n] < 10)
                        res.push_back(to_string(s1[m]) + ":0" + to_string(s2[n]));
                    else
                        res.push_back(to_string(s1[m]) + ":" + to_string(s2[n]));
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
       // vector<int> hour = { 0,1,1,2,1,2,2,3,1,2,2,3 };
        vector<int> minute(60, 0);
        int pow = 2;
        minute[0] = 0;
        minute[1] = 1;
        for (int i = 2; i < 60; i++) {
            if (i == pow * 2)
                pow = i;
            minute[i] = minute[i - pow] + 1;
        }
        vector<vector<int>> hour_h = { {0},{1,2,4,8},{3,5,6,9,10},{7,11} };
        vector<int> minute_h[6];
        for (int i = 0; i < 60; i++) {
            minute_h[minute[i]].push_back(i);
        }
        vector<string> res;
      //  vector<int> s1, s2;
        int start = num < 6 ? 0 : (num - 5);
        int end = num > 3 ? 3 : num;
        int i, j, m, n;
        for (i = start; i <= end; i++) {
            j = num - i;

            for (m = 0; m < hour_h[i].size(); m++) {
                for (n = 0; n < minute_h[j].size(); n++) {
                    if (minute_h[j][n] < 10)
                        res.push_back(to_string(hour_h[i][m]) + ":0" + to_string(minute_h[j][n]));
                    else
                        res.push_back(to_string(hour_h[i][m]) + ":" + to_string(minute_h[j][n]));
                }
            }
        }
        return res;
    }
};