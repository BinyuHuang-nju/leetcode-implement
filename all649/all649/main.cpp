#include <iostream>
using namespace std;
#include <string>
#include <queue>

class Solution {
public: //贪心：每个R阵营的参议员禁止下一个离他最近的D阵营的参议员
    string predictPartyVictory(string senate) {
        queue<int> radiant;
        queue<int> dire;
        for (int i = 0; i < senate.length(); i++) {
            if (senate[i] == 'R')
                radiant.push(i);
            else
                dire.push(i);
        }
        while (!radiant.empty() && !dire.empty()) {
            int r = radiant.front();
            int d = dire.front();
            radiant.pop();
            dire.pop();
            if (r < d)
                radiant.push(r + senate.length());
            else
                dire.push(d + senate.length());
        }
        return (radiant.empty()) ? "Dire" : "Radiant";
    }
};
